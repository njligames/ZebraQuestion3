#include "PaperStrip.h"

struct Add{
    int sum;
    Add():sum(0){}
    void operator()(int n){sum+=n;}
};

bool PaperStrip::canPerformMinPieces(const std::vector<int>& original, const std::vector<int>& desired) {
    
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

int PaperStrip::minPieces(const std::vector<int>& original, const std::vector<int>& desired) {

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

