/**
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        std::string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            res = longestCommonPrefix(res, strs[i]);
        }

        return res;
    }

    string longestCommonPrefix(string str1, string str2) {
        if (str1.size() == 0 || str2.size() == 0) {
            return "";
        }

        string res = "";
        int idx = 0;
        while (idx < str1.size() && idx < str2.size()) {
            if (str1[idx] == str2[idx]) {
                res += str1[idx++];
            } else {
                break;
            }
        }

        return res;
    }
};