
/**
 * Given a collection of numbers that might contain duplicates, return all
possible unique permutations.

    Input: [1,1,2]
    Output:
    [
    [1,1,2],
    [1,2,1],
    [2,1,1]
    ]
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res_.clear();
        if (0 == nums.size()) {
            return res_;
        }

        // 增加一个排序操作
        sort(nums.begin(), nums.end());

        used_ = vector<bool>(nums.size(), false);
        vector<int> tmp_vec;
        GetPermute2(nums, 0, tmp_vec);

        return res_;
    }

   private:
    void GetPermute(vector<int>& nums, int index, vector<int>& tmp_vec) {
        if (index == nums.size()) {
            res_.emplace_back(tmp_vec);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used_[i]) {
                // 剪枝，used_[i-1]被撤销（重置false）后再被选择，会导致重复，
                // 也可以记录上一次的
                if (i > 0 && nums[i] == nums[i - 1] && !used_[i - 1]) {
                    continue;
                }

                tmp_vec.emplace_back(nums[i]);
                used_[i] = true;
                GetPermute(nums, index + 1, tmp_vec);
                tmp_vec.pop_back();
                used_[i] = false;
            }
        }
        return;
    }

    void GetPermute2(vector<int>& nums, int index, vector<int>& tmp_vec) {
        if (index == nums.size()) {
            res_.emplace_back(tmp_vec);
            return;
        }
        // 记录上一次的搜索起点，初始值一定不能存在于nums中，可以为排序后的nums的nums[0]-1或nums[len]+1
        int pre_search = nums[0] - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (!used_[i] && pre_search != nums[i]) {
                // //
                // 剪枝，used_[i-1]被撤销（重置false）后再被选择，会导致重复，
                // // 也可以记录上一次的
                // if (i > 0 && nums[i] == nums[i - 1] && !used_[i - 1]) {
                //     continue;
                // }

                tmp_vec.emplace_back(nums[i]);
                used_[i] = true;
                GetPermute(nums, index + 1, tmp_vec);
                tmp_vec.pop_back();
                used_[i] = false;

                pre_search = nums[i];
            }
        }
        return;
    }

    vector<vector<int>> res_;
    vector<bool> used_;
};

int main(int argc, char* argv[]) {
    vector<int> nums{1, 1, 2};

    Solution sln;
    auto res = sln.permuteUnique(nums);

    Utils<int> util;
    util.PrintVector2D(res);

    return 0;
}