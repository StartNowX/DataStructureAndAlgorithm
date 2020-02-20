/**
 *Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.

    Input: "aab"
    Output:
    [
        ["aa","b"],
        ["a","a","b"]
    ]
 */

#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        if (0 == s.size()) {
            return res_;
        }

        vector<string> cur_res;
        FindPalindrome(s, cur_res);

        return res_;
    }

   private:
    void FindPalindrome(const string& s, vector<string>& cur_res) {
        if ("" == s) {
            res_.emplace_back(cur_res);
            return;
        }

        for (int i = 1; i <= s.size(); ++i) {
            string sub = s.substr(0, i);
            if (IsPalindrome(sub)) {
                cur_res.emplace_back(sub);
                FindPalindrome(s.substr(i, s.size() - i), cur_res);
                // 走到这一步，说明上一步找到子串不是回文串，这种分割方式就有问题，需要退出
                cur_res.pop_back();
            }
        }
        return;
    }
    bool IsPalindrome(const string& s) {
        if (0 == s.size()) {
            return false;
        }

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> res_;
};

int main(int argc, char* argv[]) {
    string intpu_str = "aab";

    Solution sln;
    auto res = sln.partition(intpu_str);

    Utils<string> util;
    util.PrintVector2D(res);

    return 0;
}