/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system
connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
money you can rob tonight without alerting the police.

    Input: [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
                 Total amount you can rob = 1 + 3 = 4.

    Input: [2,7,9,3,1]
    Output: 12
    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
                 Total amount you can rob = 2 + 9 + 1 = 12.

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
        dp[0] = nums[0];
        // 这里dp[1]需要取前两次的最大值
        dp[1] = MAX(nums[0], nums[1]);
        for (int i = 2; i < length; ++i) {
            dp[i] = MAX((dp[i - 2] + nums[i]), dp[i - 1]);
        }
        return dp[length - 1];
    }
};

int main(int argc, const char** argv) {
    // {2,7,9,3,1}  {1, 2, 3, 1}
    std::vector<int> nums{2, 7, 9, 3, 1};

    Solution sln;
    int res = 0;
    {
        TimeLog time("robber_house");
        res = sln.rob(nums);
    }

    std::cout << "res = " << res << std::endl;

    return 0;
}