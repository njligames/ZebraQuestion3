#include <iostream>
#include <vector>
using namespace std;

struct Add{
    int sum;
    Add():sum(0){}
    void operator()(int n){sum+=n;}
};

static bool canPerformMinPieces(const std::vector<int>& original, const std::vector<int>& desired) {
    
    if(original.size() == desired.size()) {
        std::vector<int> temp_orginal;
        std::copy(original.begin(), original.end(), back_inserter(temp_orginal));
        std::sort(temp_orginal.begin(), temp_orginal.end());
        
        std::vector<int> temp_desired;
        std::copy(desired.begin(), desired.end(), back_inserter(temp_desired));
        std::sort(temp_desired.begin(), temp_desired.end());
        
        if( temp_desired == temp_orginal) {
            const unsigned long summation((temp_orginal.size() * (temp_orginal.size()+1))/2);
            
            const Add t = for_each(temp_orginal.begin(), temp_orginal.end(), Add());
            if(t.sum == summation) {
                const unsigned long summation((temp_desired.size() * (temp_desired.size()+1))/2);
                
                const Add t = for_each(temp_desired.begin(), temp_desired.end(), Add());
                return (summation == t.sum);
                
            }
        }
    }
    return false;
}

/*
 You are given two paper strips. On each strip, numbers (1, 2, ...N) are written
 in random order. Cut the original paper strip into several pieces and rearrange
 those pieces to form the desired sequence.
 
 Write a function that, efficiently with respect to time used, returns the minimum
 number of cut pieces needed to perform the described operation.
 
 For example, the following code should display 3 because the pieces used
 should be (1), (4, 3), and (2)
 
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired =  { 1, 2, 4, 3 };
    std::cout << minPieces(original, desired) << std::endl;
 
 Assumptions
    * Both vectors are of the same set of integers.
    * The set of integers do not have a repeated integers.
    * All numbers are accounted for (1, 2, ...vector.size())
 
 @param original The paper strip to cut.
 @param desired The paper strp to match.
 @return The minimum number of cut pieces need to perform the described operation.
 */
int minPieces(const std::vector<int>& original, const std::vector<int>& desired) {

    int min_cuts(numeric_limits<int>::max());
    int start_index = 0;
    
    /*
     Loop through the original sequence and compare the current value of the desired sequence
     to the current value of the original sequence; if it is contiguious, decrement the cuts variable.

     if the number of cuts are smaller, store it.
     
     once you reach the end of the desired array, increment the starting position.

     Repeat the above algorithm until the starting position is greater then the size of the original.
     
     */
    bool started_continuous(false);
    int cuts((int)original.size() - 1);
    for(int original_index = start_index; original_index < original.size(); ) {
        
        
        for(int desired_index = 0; desired_index < desired.size(); ) {
            
            if(original_index >= original.size()) {
                original_index = 0;
                started_continuous = false;
            }
            
            if(original[original_index] == desired[desired_index]) {
                if(started_continuous) {
                    cuts--;
                }
                started_continuous = true;
                
                original_index++;
                
            } else {
                started_continuous = false;
            }
            
            desired_index++;
        }
        
        if(original_index >= original.size() - 1) {
            min_cuts = min(min_cuts, cuts);

            started_continuous = false;
            
            start_index++;
            original_index = start_index;
            cuts = (int)original.size() - 1;
        } else {
            original_index++;
        }
    }

    if(numeric_limits<int>::max() == min_cuts)
        return 0;
    return min_cuts + 1;
}

static const std::string ERROR_STRING("Error: The values in the arrays are incorrect.");
static int test1() {
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired =  { 1, 2, 4, 3 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
    
}

static int test2() {
    // NOTE: These datasets do work with minPieces, but they do not satisfy
    // the requirements according to the specifications. (non sequential)
    std::vector<int> original = { 1, 4, 3, 2, 7, 8, 9 };
    std::vector<int> desired =  { 1, 2, 4, 3, 9, 7, 8 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test3() {
    // NOTE: These datasets do work with minPieces, but they do not satisfy
    // the requirements according to the specifications. (non sequential)
    std::vector<int> original = { 1, 4, 3, 2, 7, 8, 9 };
    std::vector<int> desired =  { 1, 2, 4, 3, 7, 8, 9 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test4() {
    std::vector<int> original = { 1 };
    std::vector<int> desired =  { 1 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test5() {
    std::vector<int> original = { 1, 2 };
    std::vector<int> desired =  { 2, 1 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test6() {
    std::vector<int> original = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    std::vector<int> desired =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test7() {
    std::vector<int> original = { };
    std::vector<int> desired =  { };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test8() {
    // Invalid data set (array of different sizes)
    std::vector<int> original = { };
    std::vector<int> desired =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

static int test9() {
    // Invalid data set (array does not have sequential values)
    std::vector<int> original = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16 };
    std::vector<int> desired =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16 };
    
    if(!canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (minPieces(original, desired));
}

#ifndef RunTests
int main()
{
    int val(0);
    
    try {
        val = test1();
        assert(3 == val && "Test 1 failed");
        std::cout << val << " - (1), (4, 3), and (2)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test2();
        assert(5 == val && "Test 2 failed");
        std::cout << val << " - (1), (2), (4, 3), (9), and (7, 8)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test3();
        assert(4 == val && "Test 3 failed");
        std::cout << val << " - (1), (2), (4, 3), and (7, 8, 9)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test4();
        assert(1 == val && "Test 4 failed");
        std::cout << val << " - (1)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test5();
        assert(2 == val && "Test 5 failed");
        std::cout << val << " - (1), and (2)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test6();
        assert(1 == val && "Test 6 failed");
        std::cout << val << " - (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test7();
        assert(0 == val && "Test 7 failed");
        std::cout << val << " - " << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test8();
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test9();
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    return 0;
}
#endif
