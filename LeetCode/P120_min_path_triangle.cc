/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row
below.

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

#include <iostream>
#include <vector>


using namespace std;

class Solution {
   public:
    // 自上向下的方式，还有自下向上的方式
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (0 == rows) {
            return 0;
        }
        // 这里只需要O(n)的空间即可，因为每行只能取一个数
        // dp最大长度==triangle底边长度
        vector<int> dp(rows, 0);
        dp[0] = triangle[0][0];
        // pre_val: dp[i-1][j-1], cur: dp[i-1][j]
        int pre_val = 0, cur;
        for (int i = 1; i < rows; ++i) {
            for (int c = 0; c <= i; ++c) {
                cur = dp[c];
                // 最左边
                if (c == 0) {
                    dp[c] = cur + triangle[i][c];
                } else if (c == i) {
                    dp[c] = pre_val + triangle[i][c];
                } else {
                    dp[c] = std::min(cur, pre_val) + triangle[i][c];
                }
                pre_val = cur;
            }
        }

        int min = INT32_MAX;
        for (auto s : dp) {
            min = s < min ? s : min;
        }

        return min;

        /* 有问题的方法，可能当前层用a点最小，但是到下一层总体看就是用b最小
        比如，第二层[[-1],[2,3],[1,-1,-3]]，按这个方法是2最小，实际综合第三层是第3最小
        // 记录上一层的最小值的index，所以不需要对每列进行遍历了
        int dp_min_index = 0;
        // dp[0] = 1;
        for (int r = 0; r < rows; ++r) {
            if (r == 0) {
                dp[r] = triangle[r][dp_min_index];
            } else {
                dp_min_index = triangle[r][dp_min_index] < triangle[r][dp_min_index+1] ? dp_min_index : dp_min_index +
        1; dp[r] = dp[r-1] + triangle[r][dp_min_index];
            }

        }

        return dp[rows-1];*/
    }
};

int main(int argc, char* argv[]) { return 0; }