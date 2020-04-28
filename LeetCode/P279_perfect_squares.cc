/**
 * Given a positive integer n, find the least number of perfect square numbers  which sum
to n.
    Input: n = 12
    Output: 3
    Explanation: 12 = 4 + 4 + 4.

    Input: n = 13
    Output: 2
    Explanation: 13 = 4 + 9.
*/

#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    //    f(k) = 1 + min{f(k - 1^2), f(k - 2^2), f(k - 3^3)...}
    int numSquares(int n) {
        // dp[i]表示i能够被分解的最少平方数的个数
        vector<int> dp(n + 1, 0);

        // 不能从0开始遍历,
        for (int i = 1; i <= n; ++i) {
            int min_cnt = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                min_cnt = std::min(min_cnt, dp[i - j * j]);
            }
            // 加上dp[0]的值
            dp[i] = min_cnt + 1;
        }

        return dp[n];
    }

    // 另一种方法
    // 四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。
    // 推论：满足四数平方和定理的数n（四个整数的情况），必定满足 n=4^a(8b+7)
};


int main(int argc, char* argv[]) {
    int given_num = 13;

    Solution sln;
    auto res = sln.numSquares(given_num);
    std::cout << "res = " << res << std::endl;

    return 0;
}