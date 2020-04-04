/**
 * 斐波那契数列
 *
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        // 1. 递归
        // return fib(n - 1) + fib(n - 2);

        // 2. dp, O(n)的空间复杂度
        // vector<int> dp(n + 1, 0);
        // dp[0] = 0;
        // dp[1] = 1;
        // for (int i = 2; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n] % 1000000007;

        // 3. dp, O(1)的空间复杂度
        int a = 0, b = 1;
        int sum = a + b;
        // 注意要包含n
        for (int i = 2; i <= n; ++i) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;
    auto res = sln.fib(10);
    std::cout << "res = " << res << std::endl;

    return 0;
}