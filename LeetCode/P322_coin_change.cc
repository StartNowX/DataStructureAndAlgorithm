/**
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the
 * fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Note: You may assume that you have an infinite number of each kind of coin.
 *
 * Input: coins = [1, 2, 5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

    Input: coins = [2], amount = 3
    Output: -1
 */

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 自下向上的dp
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0 || amount == 0) {
            return 0;
        }

        // dp[i]表示组成面值i需要最少的coin
        vector<int> dp(amount + 1, amount + 1);
        // 没有面值为0的
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (size_t j = 0; j < coins.size(); ++j) {
                // coins[j]若大于i，没有放进去的必要了
                if (coins[j] <= i) {
                    // 对每一个值i，都遍历所有可能的面值的选择
                    // 这里dp[i - coins[j]]相当于对dp[i]进行拆分了，可能一个面值的硬币被使用了多次，
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // 假如没法组成的话，amount从1开始遍历时就在不停的+1，相当于执行了amount次+1操作
        return dp[amount] > amount ? -1 : dp[amount];
    }

    // int coinChangeError(vector<int>& coins, int amount) {
    //     if (coins.size() == 0 || amount == 0) {
    //         return 0;
    //     }

    //     int cnt = 0;
    //     std::sort(coins.begin(), coins.end(), [](int& a, int& b) { return a > b; });
    //     int x = amount / coins[0];
    //     int y = amount % coins[0];
    //     amount -= y;
    //     cnt += x;
    // 这里这样处理逻辑不对
    //     for (int i = 1; i < coins.size(); ++i) {
    //         x = amount / coins[i];
    //         y = amount % coins[i];

    //         amount -= y;
    //         cnt += x;
    //         if (0 == amount) {
    //             return cnt;
    //         }
    //     }

    //     if (amount == 0) {
    //         return cnt;
    //     } else {
    //         return -1;
    //     }
    // }

    int coinChange2nd(vector<int>& coins, int amount) {
        if (coins.size() == 0) {
            return -1;
        }

        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(int argc, char* argv[]) {
    vector<int> vec{2, 5, 10, 1};
    int amount = 27;

    Solution sln;
    auto res = sln.coinChange2nd(vec, amount);
    cout << "res = " << res << std::endl;
}