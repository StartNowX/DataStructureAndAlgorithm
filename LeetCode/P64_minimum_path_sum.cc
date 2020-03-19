/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

    Input:
    [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    Output: 7
    Explanation: Because the path 1→3→1→1→1 minimizes the sum.

 */

#include <iostream>
#include <vector>

#include "utils/include/time_log.h"
#include "utils/include/utils.h"

using namespace std;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        if (0 == grid.size()) {
            return 0;
        }

        if (0 == grid[0].size()) {
            return 0;
        }

        int col = grid.size();
        int row = grid[0].size();

        int dp[grid.size()][grid[0].size()] = {0};

        dp[0][0] = grid[0][0];
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                if (0 == i && 0 == j) {
                    dp[i][j] = grid[i][j];
                } else if (0 == i) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (0 == j) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = MIN(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
                // std::cout << "dp[i][j] = " << dp[i][j] << std::endl;
            }
        }

        return dp[col - 1][row - 1];
    }
};

int main(int argc, const char** argv) {
    // {2,7,9,3,1}  {1, 2, 3, 1} {2, 7, 9, 3, 1}
    std::vector<std::vector<int>> nums{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution sln;
    int res = 0;
    {
        TimeLog time("minPathSum");
        res = sln.minPathSum(nums);
        std::cout << "res = " << res << std::endl;
    }

    return 0;
}