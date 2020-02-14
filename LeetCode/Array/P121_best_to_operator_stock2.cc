/**
 * Say you have an array for which the ith element is the price of a given stock
on day i.
 * Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (i.e., buy one and sell one share of the stock multiple
times).
 * Note: You may not engage in multiple transactions at the same time (i.e., you
must sell the stock before you buy again).
 *
 * Input: [7,1,5,3,6,4] Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
5-1 = 4. Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit =
6-3 = 3.
*/

#include <cstdlib>
#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// 贪心算法，每天只要有收益就加入（即，差值序列中只加入正数）
int MaxProfit2(vector<int>& prices) {
    if (prices.size() < 1) {
        return 0;
    }

    int cur_profit = 0;
    int max_profit = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        cur_profit = std::max(0, prices[i + 1] - prices[i]);
        max_profit += cur_profit;
    }

    return max_profit;
}

int main(int argc, char* argv[]) {
    // {7, 1, 5, 3, 6, 4};  //{7, 1, 5, 3, 6, 4}; //{7, 6, 4, 3, 1};// {1,2};
    // {7,6,4,3,1}; //{7, 1, 5, 3, 6, 4};  //
    vector<int> all_nums{1, 2, 3, 4, 5};

    Utils<int> util;
    util.PrintVector(all_nums);

    int res = MaxProfit2(all_nums);

    cout << "best time to sell: " << res << endl;

    util.PrintVector(all_nums);

    return 0;
}