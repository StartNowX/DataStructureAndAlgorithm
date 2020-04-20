/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
*/


#include <iostream>
#include <string>

#include "utils/include/time_log.h"
#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    // 注意和题目516（最长回文子序列）区分，这里不是子序列，是子串
    string longestPalindrome(string s) {
        if (s.length() <= 0) {
            return "";
        }

        int substr_start = 0;
        int substr_end = 0;
        int len = 0;
        int len_odd = 0, len_even = 0;
        for (int i = 0; i < s.length(); ++i) {
            // 以元素i为中心，技术情况下
            len_odd = ExpandCenter(s, i, i);
            // 以元素i和i+1之间为中心，偶数情况下
            len_even = ExpandCenter(s, i, i + 1);
            len = len_odd > len_even ? len_odd : len_even;

            if (len > substr_end - substr_start) {
                substr_start = i - (len - 1) / 2;
                substr_end = i + len / 2;
            }
        }

        // 这里不能直接用len，可能len会被后面小的len替换掉
        return s.substr(substr_start, substr_end - substr_start + 1);
    }

   private:
    int ExpandCenter(const std::string& s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        // 注意这里是-1，因为while循环退出时，L和R都变化了一次，相当于(R-1)-(L+1)-1=R-L-1
        return R - L - 1;
    }
};

int main(int argc, char* argv[]) {
    std::string str = "babad";

    Solution sln;
    {
        TimeLog scope("longestPalindrome");
        auto res = sln.longestPalindrome(str);
        std::cout << "res = " << res << std::endl;
    }

    return 0;
}