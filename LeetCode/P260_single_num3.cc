/**
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
exactly twice. Find the two elements that appear only once.

    Input:  [1,2,1,3,2,5]
    Output: [3,5]
*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for (auto& num : nums) {
            mask ^= num;
        }

        // 至此, mask中保留的是两个仅出现一次的数异或的结果(如x, y)
        // 不能直接通过mask区分出两个数x和y，但是最右边的一个bit的1，其要不来着x, 要不来自y, 这样便可以区分了
        int diff = (mask & (-mask));  // 保留最右边的为1的bit位
        vector<int> res(2, 0);
        for (auto& num : nums) {
            if (diff & num) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> input{1, 2, 1, 3, 2, 5};

    Solution sln;
    auto res = sln.singleNumber(input);

    Utils<int> util_int;
    util_int.PrintVector(res);

    return 0;
}