/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Input: [2,2,1]
    Output: 1

    Input: [2,2,1]
    Output: 1
*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int once_flag = 0;

        for (auto num : nums) {
            once_flag = once_flag ^ num;
        }

        return once_flag;
    }
};

int main(int argc, char* argv[]) {
    vector<int> input{2, 2, 3, 3, 1, 1, 9};

    Solution sln;
    auto res = sln.singleNumber(input);

    std::cout << "res = " << res << std::endl;

    return 0;
}