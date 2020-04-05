/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 *
 * 输入：nums = [1,2,3,4]
 * 输出：[1,3,2,4]
 * 注：[3,1,2,4] 也是正确的答案之一。
 */

#include <iostream>
#include <vector>

#include "../utils/include/utils.h"

using namespace std;

class Solution {
   public:
    // 引入额外的空间，存放是否是奇数或偶数的判断
    vector<int> exchange(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }

        vector<bool> is_odd(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) {
                res.emplace_back(nums[i]);
                is_odd[i] = true;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!is_odd[i]) {
                res.emplace_back(nums[i]);
            }
        }

        return res;
    }

    // 双指针，左边向右移动找偶数，右边向左移动找奇数
    vector<int> ExchangeEfficient(vector<int>& nums) {
        vector<int> res;
        if (0 == nums.size()) {
            return res;
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            while (left < right && IsOdd(nums[left])) left++;
            while (left < right && !IsOdd(nums[right])) right--;
            Swap(nums[left], nums[right]);
        }

        return nums;
    }

   private:
    inline bool IsOdd(int n) { return n & 0x1; }
    inline void Swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{1, 8, 10, 2, 3, 5, 4};

    Utils<int> utils_int;
    Solution sln;
    auto res = sln.ExchangeEfficient(nums);

    utils_int.PrintVector(res);


    return 0;
}
