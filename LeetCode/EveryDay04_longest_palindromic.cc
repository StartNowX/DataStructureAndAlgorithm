/**
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can
be built with those letters. This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

    Input:
    "abccccdd"

    Output:
    7

    Explanation:
    One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "utils/include/time_log.h"
#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    int longestPalindromeWithRebuilt(const string& s) {
        std::unordered_map<char, int> letter_cnt;
        for (auto& c : s) {
            letter_cnt[c]++;
        }

        // 存储回文串的长度
        int max_len = 0;
        for (auto& ele : letter_cnt) {
            int use_cnt = ele.second;
            // 对于每个字符,使用cnt/2*2次, 这里能保证max_len始终为偶数
            max_len += use_cnt / 2 * 2;

            // 对于use_cnt是奇数的情况,可以再添加一个元素
            // 但是需要保证这时候max_len是偶数,因为如果max_len是奇数,意味着在之前的回文中心已经是某个与当前字母不同的字母了,如果再把当前字母加进去,则无法构成回文串了
            if (use_cnt % 2 == 1 && max_len % 2 == 0) {
                ++max_len;
            }
        }
        return max_len;
    }
    int longestPalindrome(string s) {
        if (0 == s.length()) {
            return 0;
        }

        int start = 0, end = 0;
        int len_odd = 0, len_even = 0, len_max = 0;
        for (int i = 1; i < s.length(); ++i) {
            // 奇数情况
            len_odd = CenterExpand(s, i, i);
            // 偶数情况
            len_even = CenterExpand(s, i, i + 1);
            // 最大
            len_max = len_odd > len_even ? len_odd : len_even;
            if (len_max > end - start) {
                start = i - (len_max - 1) / 2;
                end = i + len_max / 2;
            }
        }

        return end - start + 1;
    }

   private:
    int CenterExpand(const std::string& str, int left, int right) {
        while (left > 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
};

int main(int argc, char* argv[]) {
    std::string str = "abccccdd";

    Solution sln;
    {
        TimeLog log("longestPalindrome");
        auto res = sln.longestPalindromeWithRebuilt(str);
        std::cout << "res = " << res << std::endl;
    }
}