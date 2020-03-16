/**
 * You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. In
how many distinct ways can you climb to the top?Note: Given n will be a positive integer.

    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Input: 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

*/

#include "utils/include/utils.h"
#include "utils/include/time_log.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        // 时间复杂度O(n)  空间复杂度O(n)
        if (false) {
            int dp[n] = {0};
            if (n < 3) {
                return n;
            }
            dp[0] = 1;
            dp[1] = 2;

            for (int i = 2; i < n; ++i) {
                // 到达第i个台阶的方式：
                // 第i-1个台阶，爬一个
                // 第i-2个台阶，爬两个
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n - 1];
        }

        // 时间复杂度O(n)  空间复杂度O(1)
        // 也即是斐波那契数列
        {
            int cnt_last1 = 0;
            int cnt_last2 = 0;
            int cnt_curr = 0;
            if (n < 3) {
                return n;
            }
            cnt_last2 = 1;
            cnt_last1 = 2;
            for (int i = 3; i <= n; ++i) {
                // 到达第i个台阶的方式：
                // 第i-1个台阶，爬一个
                // 第i-2个台阶，爬两个
                cnt_curr = cnt_last1 + cnt_last2;

                cnt_last2 = cnt_last1;
                cnt_last1 = cnt_curr;
            }
            return cnt_curr;
        }
    }
};

int main(int argc, const char** argv) {
    int stairs_num = 6;

    Solution sln;
    int res = 0;
    {
        TimeLog time("clim_stairs");
        res = sln.climbStairs(stairs_num);
    }

    std::cout << "res = " << res << std::endl;

    return 0;
}