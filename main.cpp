#include <iostream>
#include <vector>
using namespace std;

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
    for(int original_index = start_index; original_index < original.size(); ) {
        int cuts((int)original.size() - 1);
        
        for(int desired_index = 0; desired_index < desired.size(); ) {
            if(original[original_index] == desired[desired_index]) {
                if(started_continuous) {
                    cuts--;
                }
                started_continuous = true;
            } else {
                started_continuous = false;
            }
            
            desired_index++;
            original_index++;
            if(original_index >= original.size()) {
                original_index = 0;
                started_continuous = false;
            }
        }
        
        min_cuts = min(min_cuts, cuts);

        //reached the end, it cannot be continuous
        started_continuous = false;
        
        start_index++;
        original_index = start_index;
        
    }
    return min_cuts;
}

#ifndef RunTests
int main()
{
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired =  { 1, 2, 4, 3 };
    std::cout << minPieces(original, desired) << std::endl;
}
#endif
