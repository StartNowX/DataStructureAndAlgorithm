/**
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once.
Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Input: [2,2,3,2]
    Output: 3

    Input: [0,1,0,1,0,1,99]
    Output: 99
*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int once_flag = 0;
        int twice_flag = 0;

        // x ^ x = 0
        // x ^ 0 = x
        // 但是这不能区分出现一次和出现三次的情况，因此引入出现一次和出现两次的标志
        // 只有出现两次的标志（twice_flag）未改变时，才改变出现一次的标志（once_flag）
        // 只有出现一次的标志（once_flag）未改变时，才改变出现两次的标志（twice_flag）
        for (auto num : nums) {
            once_flag = ~twice_flag & (once_flag ^ num);
            twice_flag = ~once_flag & (twice_flag ^ num);
        }

        return once_flag;
    }
};

int main(int argc, char* argv[]) {
    vector<int> input{2, 2, 3, 2};

    Solution sln;
    auto res = sln.singleNumber(input);

    std::cout << "res = " << res << std::endl;

    return 0;
}