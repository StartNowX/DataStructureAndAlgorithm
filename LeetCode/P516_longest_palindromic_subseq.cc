/**
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s
is 1000.

"bbbab"
4
One possible longest palindromic subsequence is "bbbb".
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 注意和题目5（最长回文子串）区分，这里不是子串，是子序列
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        if (0 == len) {
            return 0;
        }

        // dp不能初始化为1，否则会导致有时会多加1次，比如当bbbab序列，当i=2，j=3时
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = len - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][len - 1];
    }
};

int main(int argc, char* argv[]) { return 0; }