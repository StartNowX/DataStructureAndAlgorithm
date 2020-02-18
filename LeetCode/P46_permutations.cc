/**
 * Given a collection of distinct integers, return all possible permutations.
 *  Input: [1,2,3]
    Output:
        [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
        ]
 */

#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        res_.clear();
        if (0 == nums.size()) {
            return res_;
        }
        used_ = vector<bool>(nums.size(), false);

        vector<int> tmp_vec;
        CombinateNum(nums, 0, tmp_vec);

        return res_;
    }

   private:
    void CombinateNum(vector<int>& nums, const int index,
                      vector<int> tmp_num_vec) {
        if (index >= nums.size()) {
            res_.emplace_back(tmp_num_vec);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used_[i]) {
                tmp_num_vec.emplace_back(nums[i]);
                used_[i] = true;
                CombinateNum(nums, index + 1, tmp_num_vec);
                tmp_num_vec.pop_back();
                used_[i] = false;
            }
        }

        return;
    }

    vector<vector<int>> res_;
    vector<bool> used_;
};

int main(int argc, char* argv[]) {
    vector<int> nums{1, 2, 3};

    Solution sln;
    auto res = sln.permute(nums);

    Utils<int> util;
    util.PrintVector2D(res);

    return 0;
}