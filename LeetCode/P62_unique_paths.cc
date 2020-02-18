/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
the diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

1. Input: m = 3, n = 2, Output: 3
2. Input: m = 7, n = 3, Output: 3
*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// dp思想，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
int UniquePaths(int m, int n) {
    // space complexity O(n^2)
    /*int dp[m][n] = {{0}};

    // 边界置为1
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];*/

    // space complexity O(n)
    // 只需要记录上一行和当前行，而上一行j又等于没更新前的当前行的j
    int dp[n] = {1};

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // dp[j] = dp[j] + dp[j-1], 等价于dp[j]=last_row[j] + dp[j-1]
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main(int argc, char* argv[]) {
    int m = 7;
    int n = 3;

    auto res = UniquePaths(m, n);
    cout << "res = " << res << endl;

    return 0;
}