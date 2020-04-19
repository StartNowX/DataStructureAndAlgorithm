/**
 * Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted
without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is
not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        if (len1 == 0 || len2 == 0) {
            return 0;
        }

        // len1和len2各自+1，来存储空字符串的情况，table的最左上的点
        // 增加了一个维度，最后的最大值肯定是dp_table[len1][len2]，注意下面比较时是比较i-1和j-1对应的元素
        vector<vector<int> > dp_table(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                // 边界条件，这里比较的是i-1和j-1
                if (text1[i - 1] == text2[j - 1]) {
                    dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
                } else {
                    dp_table[i][j] = std::max(dp_table[i - 1][j], dp_table[i][j - 1]);
                }
            }
        }
        return dp_table[len1][len2];
    }

   public:
    /**
     * 该思路认为最长公共子串一定出现在最短的字符串中，大部分case能够处理
     * 但是对于"pmjghexybyrgzczy","hafcdqbgncrcbihkd"这样的情况，就不能够处理了，最长的公共子串出现在较长的那个，是4个，而如果以较短的字符串为基准，则是3个
     */
    int longestCommonSubsequenceErr(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        if (len1 == 0 || len2 == 0) {
            return 0;
        }

        std::string shortest_str;
        std::string longest_str;
        int len_long, len_short;
        if (len1 > len2) {
            shortest_str = text2;
            len_short = len2;

            longest_str = text1;
            len_long = len1;
        }

        vector<int> dp(len_short, 0);

        int last_index = -1;
        for (int i = 0; i < len_short; ++i) {
            int index_i = GetIndex(longest_str, shortest_str[i]);
            if (-1 == index_i) {
                dp[i] = 0;
                continue;
            }

            for (int j = 0; j <= i; ++j) {
                int index_j = GetIndex(longest_str, shortest_str[j]);
                if (index_j <= index_i && index_j != -1) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int max_value = 0;
        for (auto x : dp) {
            max_value = std::max(x, max_value);
        }

        return max_value;
    }

   private:
    int GetIndex(const std::string& str, char c) {
        int i = 0;
        for (auto s : str) {
            if (c == s) {
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    string text1 = "abcde";
    string text2 = "abe";

    Solution sln;
    auto res = sln.longestCommonSubsequence(text1, text2);
    std::cout << "res = " << res << std::endl;

    return 0;
}