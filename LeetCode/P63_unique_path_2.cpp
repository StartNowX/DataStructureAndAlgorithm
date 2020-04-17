/**
 *A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner
of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?


Note: m and n will be at most 100.

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if (rows == 0 || cols == 0) {
            return 0;
        }

        // 注意m、n的范围是100，所以int会放不完
        vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
        // 特殊case，input=[[1]], 输出应该是0
        dp[0][0] = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!obstacleGrid[r][c]) {
                    if (r == 0 && c == 0) {
                        dp[r][c] = 1;
                    } else if (r == 0) {
                        dp[r][c] = dp[r][c - 1];
                    } else if (c == 0) {
                        dp[r][c] = dp[r - 1][c];
                    } else {
                        dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                    }
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

int main(int argc, char* argv[]) { return 0; }