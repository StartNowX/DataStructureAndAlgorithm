/**
 * Given a string, find the length of the longest substring without repeating characters.

    Input: "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
                Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    // 滑动窗方法
    int lengthOfLongestSubstring(string s) {
        int len = static_cast<int>(s.length());
        if (0 == len) {
            return 0;
        }

        int start{0}, end{0}, max_len(0), tmp_len{0};
        while (end < len) {
            string sub_str = s.substr(start, end - start);
            // 没找到
            if (sub_str.find(s[end]) == sub_str.npos) {
                tmp_len = end - start + 1;
                max_len = max_len < tmp_len ? tmp_len : max_len;

                end++;
            } else {
                start++;
            }
        }
        return max_len;
    }

    // 滑动窗+hashmap
    int lengthOfLongestSubstringWithMap(string s) {
        int len = static_cast<int>(s.length());
        if (0 == len) {
            return 0;
        }

        unordered_set<char> map;
        int start{0}, max_len{0};
        for (int i = 0; i < len; ++i) {
            // map中存在该字符，从错边开始不停移除，指导不存在为止
            while (map.find(s[i]) != map.end()) {
                map.erase(s[start]);
                start++;
            }

            max_len = std::max(max_len, i - start + 1);
            map.insert(s[i]);
        }

        return max_len;
    }

    int lengthOfLongestSubstringWrong(string s) {
        int len = s.length();

        if (0 == len) {
            return 0;
        }

        // dp[i]以i结尾的最长的的不重复子字符串长度

        // 如下使用dp方法，处理不了所有的例子，如dvdf
        vector<int> dp(len, 1);
        string last_substr;
        last_substr += s[0];
        for (int i = 1; i < len; ++i) {
            size_t index = last_substr.rfind(s[i]);
            if (last_substr.npos == index) {
                dp[i] = dp[i - 1] + 1;
                last_substr += s[i];
            } else {
                last_substr = s[i];
            }
        }

        return FindMaxEle(dp);
    }

   private:
    int FindMaxEle(const std::vector<int>& nums) {
        int max = nums[0];
        for (auto& n : nums) {
            // std::cout << " " << n;
            max = n > max ? n : max;
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    //"pwwkew";  "bbbbb";  //"abcabcbb"  "dvdf"
    string s = "abcabcbb";

    Solution sln;
    auto res = sln.lengthOfLongestSubstring(s);
    std::cout << "res = " << res << std::endl;

    return 0;
}