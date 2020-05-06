/**
 * In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the
year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel
for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 从前往后
     */
    int mincostTicketsForward(vector<int>& days, vector<int>& costs) {
        int last = days[days.size() - 1];

        vector<int> dp(last + 1, 0);
        int idx = 0;
        for (int i = 1; i <= last; ++i) {
            if (i == days[idx]) {
                int cost = INT32_MAX;
                int oneday_ago = i - 1;
                int sevenday_ago = i - 7 > 0 ? i - 7 : 0;
                int thirtyday_ago = i - 30 > 0 ? i - 30 : 0;

                cost = std::min(cost, dp[oneday_ago] + costs[0]);
                cost = std::min(cost, dp[sevenday_ago] + costs[1]);
                cost = std::min(cost, dp[thirtyday_ago] + costs[2]);

                dp[i] = cost;
                idx++;
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[last];
    }

    /**
     * 从后往前遍历
     * 越晚买票越好，当i天需要买票时，那么其有效日期为j天，那么从i到i+j之间是不需要买票的
     */
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        mem_ = std::vector<int>(366, -1);
        for (auto d : days) {
            dayset_.insert(d);
        }
        costs_ = costs;

        return DayIMinCostsDP(1);
    }

    // 从后向前遍历
    int DayIMinCostsDP(int i) {
        if (i > 365) {
            return 0;
        }

        if (mem_[i] != -1) {
            return mem_[i];
        }

        // 如果i天需要出行，则选择三种出行中代价自小的
        if (dayset_.count(i)) {
            mem_[i] = std::min(std::min(DayIMinCostsDP(i + 1) + costs_[0], DayIMinCostsDP(i + 7) + costs_[1]),
                               DayIMinCostsDP(i + 30) + costs_[2]);
        } else {
            // 如果i天不需要出行，则不需买票，直接等于下一天的
            mem_[i] = DayIMinCostsDP(i + 1);
        }
        return mem_[i];
    }

   private:
    vector<int> costs_;
    unordered_set<int> dayset_;
    // mem_表示从i天到年底所需要花的钱
    vector<int> mem_;
};


int main(int argc, char* argv[]) {
    vector<int> day{1, 4, 6, 7, 8, 20};
    vector<int> cost{2, 7, 15};

    Solution sln;
    auto res = sln.mincostTickets(day, cost);

    std::cout << "res = " << res << std::endl;

    return 0;
}