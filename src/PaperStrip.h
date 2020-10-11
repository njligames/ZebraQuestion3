#include <vector>
using namespace std;

class PaperStrip {
public:

    /*
     * Makes sure that the datasets are as required.
     *
     * Requirements:
     *  - Same length.
     *  - When sorted, cotains the same values.
     *  - Data is in sequential order, starting from 1 to vector.size()
     * 
     * @param original The paper strip to cut.
     * @param desired The paper strp to match.
     * @return true if the dataset follows the requirements.
     */
    static bool canPerformMinPieces(const std::vector<int>& original, const std::vector<int>& desired);

    /* 
     * You are given two paper strips. On each strip, numbers (1, 2, ...N) are written
     * in random order. Cut the original paper strip into several pieces and rearrange
     * those pieces to form the desired sequence.
     * 
     * Write a function that, efficiently with respect to time used, returns the minimum
     * number of cut pieces needed to perform the described operation.
     * 
     * For example, the following code should display 3 because the pieces used
     * should be (1), (4, 3), and (2)
     * 
     *    std::vector<int> original = { 1, 4, 3, 2 };
     *    std::vector<int> desired =  { 1, 2, 4, 3 };
     *    std::cout << minPieces(original, desired) << std::endl;
     * 
     * Assumptions
     *    * Both vectors are of the same set of integers.
     *    * The set of integers do not have a repeated integers.
     *    * All numbers are accounted for (1, 2, ...vector.size())
     * 
     * @param original The paper strip to cut.
     * @param desired The paper strp to match.
     * @return The minimum number of cut pieces need to perform the described operation.
     */
    static int minPieces(const std::vector<int>& original, const std::vector<int>& desired);
};

