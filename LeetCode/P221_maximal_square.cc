/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        if (matrix[0].size() == 0) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        // dp表示以i、j为正方形右下角时正方形的最大边长
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // 初始值要为0，而不能是-1，不然max_size*max_size也是1了
        int max_side = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // dp[i][j]应该由其左、上、左上三个点的最小值一起决定，下面的错误代码就是没有考虑这一项
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }

                    max_side = max(max_side, dp[i][j]);
                }

                /**
                 *  因为是square，所以两边一样
                 *
                这里处理不了[["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]这样的case，因为每次选择时，没有重复考虑左边和上边两个点，而只考虑了左上的点
                if (i == 0 || j == 0) {
                    dp[i][j] = (matrix[i][j] == '0' ? 0 : 1);
                } else {
                    if (matrix[i-1][j] == '1' && matrix[i][j-1] == '1' && matrix[i-1][j-1] == '1' && matrix[i][j] ==
                    '1') {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = (matrix[i][j] == '0' ? 0 : 1);
                    }
                }*/
            }
        }

        return max_side * max_side;
    }
};