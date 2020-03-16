/**
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those
integers. Return the maximum product you can get.

    Input: 2
    Output: 1
    Explanation: 2 = 1 + 1, 1 × 1 = 1.

    Input: 10
    Output: 36
    Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 */

#include "utils/include/utils.h"
#include "utils/include/time_log.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
   public:
    // 关键思想，将整数拆分成2和3，因为2和3不可再拆分了，对于为什么拆分成3后乘积最大(即为什么3是最优因子)，可以参考证明
    // https://mp.weixin.qq.com/s/BLf4GB303r0FKd2HxL64xw
    int integerBreakGreedy(int n) {
        if (n <= 3) {
            return n - 1;
        }

        int x = n / 3, y = n % 3;
        // 恰好被三整除
        if (0 == y) {
            return std::pow(3, x);
        }
        // 若余数为1，则退一步，余数变为4，然后选择2，即3^(x-1)*2*2
        if (1 == y) {
            return std::pow(3, x - 1) * 4;
        }

        // 余数为2，则直接乘以2
        return std::pow(3, x) * 2;
    }

    int integerBreakDP(int n) {
        // 用dp数组保存将整数拆分后的最大乘积
        int dp[n + 1] = {0};
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // i-j，表示将i拆分成j和i-j两份
                dp[i] = std::max(dp[i], std::max(dp[j], j) * (i - j));
            }
        }
        return dp[n];
    }
};

int main(int argc, const char** argv) {
    Solution sln;
    int input = 7;

    int res = 0;
    {
        TimeLog time_log("BreakingInteger");
        // res = sln.integerBreakGreedy(input);
        res = sln.integerBreakDP(input);
    }
    std::cout << "res = " << res << std::endl;

    return 0;
}