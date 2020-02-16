/**
 * Given an array nums of n integers, are there elements a, b, c in nums such
that a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// 排序+双指针
// LeetCode huya402994
// 注意多次的去重复的过程
vector<vector<int>> ThreeSum(vector<int>& nums) {
    vector<vector<int>> res;

    int len = nums.size();
    if (len < 3) {
        return res;
    }

    // 排序，升序
    sort(nums.begin(), nums.end());

    // 双指针
    for (int i = 0; i < len; ++i) {
        // 最左边的大于0或最右边小于0，肯定没有对应结果
        if (nums[0] > 0 || nums[len - 1] < 0) {
            return res;
        }
        // 去重复，同一个第一个数
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left_index = i + 1;
        int right_index = len - 1;
        while (left_index < right_index) {
            int sum = nums[i] + nums[left_index] + nums[right_index];
            if (0 == sum) {
                res.emplace_back(
                    vector<int>{nums[i], nums[left_index], nums[right_index]});
                // 去重复，同一个左侧值，右侧两个一样的值
                while ((left_index < --right_index) &&
                       nums[right_index] == nums[right_index + 1])
                    ;
                // 去重复，同一个右侧值，左侧两个一样的值
                while ((++left_index < right_index) &&
                       (nums[left_index] == nums[left_index - 1]))
                    ;
            } else if (sum < 0) {
                // 较小的值太小了，向右滑
                left_index++;
            } else {
                // 较大的值太大了，向左滑
                right_index--;
            }
        }
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{-1, 0, 1, 2, -1, -4};

    Utils<int> util;
    util.PrintVector(all_nums);

    auto res = ThreeSum(all_nums);

    util.PrintVector2D(res);

    return 0;
}