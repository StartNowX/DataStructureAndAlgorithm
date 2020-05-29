/**
 * Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k
times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat
numbers, k. For example, there won't be input like 3a or 2[4].

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;
        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 等于数字的话，需要获取整个数字，若‘32’
                string digits = GetDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {  // 注意cur是char
                // 等于字母或左括号，直接进栈
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string> sub;
                // 需要重复的串
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }

                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int rep_time = stoi(stk.back());
                stk.pop_back();
                string t, o = GetStrings(sub);
                // 构造字符串
                while (rep_time--) t += o;
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return GetStrings(stk);
    }

   private:
    string GetDigits(const string& s, size_t& ptr) {
        string ret;
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }

        return ret;
    }

    string GetStrings(const vector<string>& v) {
        string ret;
        for (const auto& e : v) {
            ret += e;
        }

        return ret;
    }
};