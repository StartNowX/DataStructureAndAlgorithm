/**
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the
 floor, and you can either start from the step with index 0, or the step with index 1.

    Input: cost = [10, 15, 20]
    Output: 15
    Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

    Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    Output: 6
    Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

*/

#include "utils/include/utils.h"
#include "utils/include/time_log.h"
#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        int dp[length] = {0};
        if (length <= 1) {
            return 0;
        }
        if (length == 2) {
            return MIN(cost[0], cost[1]);
        }

        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < length; ++i) {
            // 对于非最后的台阶，dp[x]表示到这个台阶的cost，显然要把cost[x]的值也加上
            dp[i] = MIN(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
            // 当到最后一个台阶时，可以从倒数第二个直接走两步跳过去
            if (i == length - 1) {
                dp[i] = MIN(dp[i], dp[i - 1]);
            }
        }
        return dp[length - 1];
    }
};

int main(int argc, const char** argv) {
    // {10, 15, 20}  {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}
    std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    Solution sln;
    int res = 0;
    {
        TimeLog time("clim_stairs");
        res = sln.minCostClimbingStairs(cost);
    }

    std::cout << "res = " << res << std::endl;

    return 0;
}