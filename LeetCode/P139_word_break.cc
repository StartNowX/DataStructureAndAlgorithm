/**
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be
segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

    Input: s = "leetcode", wordDict = ["leet", "code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".

    Input: s = "applepenapple", wordDict = ["apple", "pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
                Note that you are allowed to reuse a dictionary word.

    Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output: false
*/

#include <iostream>
#include <string>
#include <unordered_set>

#include "utils/include/time_log.h"
#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    //   LeetCode: 陈牧远 dp[i]表示字符串s的前i个字符能否拆分成wordDict
    bool wordBreak(string s, vector<string>& wordDict) {
        if (0 == s.length() || wordDict.size() == 0) {
            return 0;
        }

        unordered_set<string> m(wordDict.begin(), wordDict.end());

        // 优化,这个点挺有意思的,有点像KMP算法,去找i前面的位置时,不需要从0开始,因为每个单词的长度是固定的
        int max_word_len = 0;
        for (auto& word : wordDict) {
            max_word_len = std::max(max_word_len, static_cast<int>(word.length()));
        }

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.length(); ++i) {
            // for(int j = 0; j<i; ++j){
            // 优化
            for (int j = std::max(i - max_word_len, 0); j < i; ++j) {
                if (dp[j] && m.find(s.substr(j, i - j)) != m.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
    // 错误算法,处理不了这种case
    // s: "cars", dict: "car" "ca" "rs"
    // 因为car匹配后,就调到s了
    bool wordBreakBad(string s, vector<string>& wordDict) {
        if (0 == s.length() || wordDict.size() == 0) {
            return 0;
        }

        int i = 0;
        int w_len = 0;

        for (; i < s.length();) {
            bool flag = false;
            for (int j = 0; j < wordDict.size(); ++j) {
                std::string word = wordDict[j];
                w_len = word.length();
                if (s.substr(i, w_len) == word) {
                    i += w_len;
                    flag = true;
                }
            }

            if (i != 0 || flag) {
                i = 0;
                flag = false;
            } else if (!flag) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    // "leetcode"  "applepenapple" "catsandog" "cars"
    std::string str = "cars";
    // {"leet", "code"} {"apple", "pen"} {"cats", "dog", "sand", "and", "cat"} {"car","ca","rs"}
    vector<string> word_dict = {"car", "ca", "rs"};

    Solution sln;
    {
        TimeLog log("wordBreak");
        auto res = sln.wordBreak(str, word_dict);
        std::cout << "res = " << res << std::endl;
    }
}