/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of
all the elements of nums except nums[i].

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole
array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of
space complexity analysis.)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 构造两个空数组，一个表示i元素左边的所有元素的乘积，一个表示i元素右边的所有元素乘积，最终结果中，索引i的数字是i左侧元素的乘积和右侧元素的乘积的积
     *
     * 不允许使用除法、时间复杂度O(n)
     *
     * 如果求所有元素乘积，对相应位置再除以相应位置元素，则没法处理0的情况
     */
    vector<int> productExceptSelfFast(vector<int>& nums) {
        int length = nums.size();
        if (0 == length) {
            return vector<int>{};
        }

        // 用一个ans代替L和R
        vector<int> ans(length);
        // 赋值L数组，i为0时，L[0]=1, 因为左侧没有元素了, 对R也一样
        ans[0] = 1;
        for (int i = 1; i < length; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int R = 1;
        for (int i = length - 1; i >= 0; --i) {
            ans[i] *= R;
            R *= nums[i];
        }

        return ans;
    }


    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        if (0 == length) {
            return vector<int>{};
        }

        // 左侧所有元素的积，右侧所有元素的积，空间复杂度O(n)
        vector<int> L(length, 0), R(length, 0);
        vector<int> ans(length);
        // 赋值L数组，i为0时，L[0]=1, 因为左侧没有元素了, 对R也一样
        L[0] = 1;
        for (int i = 1; i < length; ++i) {
            L[i] = L[i - 1] * nums[i - 1];
        }

        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; --i) {
            R[i] = R[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < length; ++i) {
            ans[i] = L[i] * R[i];
        }

        return ans;
    }
};