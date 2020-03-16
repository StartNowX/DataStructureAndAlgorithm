/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent
houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
money you can rob tonight without alerting the police.

    Input: [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
                 because they are adjacent houses.

    Input: [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                 Total amount you can rob = 1 + 3 = 4.

 */

#include "utils/include/utils.h"
#include "utils/include/time_log.h"
#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

class Solution {
   public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length <= 0) {
            return 0;
        }

        if (length == 1) {
            return nums[0];
        }
        if (length == 2) {
            return MAX(nums[0], nums[1]);
        }

        int dp[length] = {0};

        // 不考虑最后一个
        int last = nums[length - 1];  // 这里需要对最后一个数先备份，后面不考虑第一个时，再将其重置
        nums[length - 1] = 0;

        dp[0] = nums[0];
        dp[1] = MAX(nums[0], nums[1]);  // 这里dp[1]需要取前两次的最大值
        CalDp(dp, nums, length);
        int tmp = dp[length - 1];

        // 不考虑第一个
        nums[length - 1] = last;
        nums[0] = 0;

        dp[0] = nums[0];
        dp[1] = MAX(nums[0], nums[1]);
        CalDp(dp, nums, length);

        return MAX(tmp, dp[length - 1]);
    }

   private:
    void CalDp(int dynamic[], std::vector<int>& nums, int len) {
        for (int i = 2; i < len; ++i) {
            dynamic[i] = MAX((dynamic[i - 2] + nums[i]), dynamic[i - 1]);
        }
    }
};

int main(int argc, const char** argv) {
    // {2,7,9,3,1}  {1, 2, 3, 1} {2, 7, 9, 3, 1}
    std::vector<int> nums{1, 2, 3, 1};

    Solution sln;
    int res = 0;
    {
        TimeLog time("robber_house");
        res = sln.rob(nums);
    }

    std::cout << "res = " << res << std::endl;

    return 0;
}