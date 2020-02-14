/**
 * Say you have an array for which the ith element is the price of a given stock
on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one
and sell one share of the stock), design an algorithm to find the maximum
profit.
 * Note that you cannot sell a stock before you buy one.
 *
 * Input: [7,1,5,3,6,4] Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
6-1 = 5. Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 * Input: [7,6,4,3,1] Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// O(n^2)
int MaxProfit(vector<int>& prices) {
    int max_profit = 0;
    int best_sell_index = 0;
    for (int i = 0; i < prices.size(); ++i) {
        for (int j = i; j < prices.size(); ++j) {
            int tmp_profit = prices[j] - prices[i];
            if (tmp_profit >= 0) {
                if (max_profit < tmp_profit){
                    max_profit = tmp_profit;
                    best_sell_index = j;
                }
            }
        }
    }
    // 让输出的是最大利润
    // best_sell_index = (0 == max_profit) ? 0 : (best_sell_index + 1);
    return max_profit;
}

// O(n) DP
// 第i天的最大收益等于：第i天抛出的收益与第i-1天抛出的收益中的最大值
// 还有一种区间和和区间差相互转换的方式, 转换成求【差值数组中最大连续子数组和的问题】
int MaxProfitDP(vector<int>& prices) {
    // 第i天的最大收益等于：第i天抛出的收益与第i-1天抛出的收益中的最大值
    int len = prices.size();

    if (len <= 1) {
        return 0;
    }
    int max_profit = 0;
    int min_input = prices[0];

    for (auto price:prices) {
        min_input = price < min_input ? price : min_input;
        max_profit = (price - min_input) > max_profit ? (price - min_input) : max_profit;
    }
    return max_profit;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{1, 2}; //{7, 1, 5, 3, 6, 4}; //{7, 6, 4, 3, 1};// {1, 2};  //{7,6,4,3,1};//{7, 1, 5, 3, 6, 4};  //

    Utils<int> util;
    util.PrintVector(all_nums);

    int res = MaxProfit(all_nums);

    cout << "best time to sell: " << res << endl;

    util.PrintVector(all_nums);

    return 0;
}