/**
 * You are given coins of different denominations and a total amount of money. Write a function to compute the number of
combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /** 策略，
     * 从基本情况没有硬币开始，一一添加硬币(若总金额为0，则组合只能为0)
     * 对于每个添加的硬币，从金额0到amount开始递归计算组合数（因为coin前的数值不会被影响，所以可以从coin开始遍历）
     */
    int change(int amount, vector<int>& coins) {
        if (amount == 0 || coins.size() == 0) {
            return 0;
        }

        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto coin : coins) {
            for (int i = coin; i < amount + 1; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

int main(int argc, char* argv[]) {
    vector<int> coins{1, 2, 5};
    int amount = 5;

    Solution sln;
    auto res = sln.change(amount, coins);
    std::cout << "res = " << res << std::endl;

    return 0;
}