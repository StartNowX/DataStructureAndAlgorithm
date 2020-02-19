/**
 * Given a string S, we can transform every letter individually to be lowercase
or uppercase to create another string.  Return a list of all possible strings we
could create.

Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

*/

#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<string> letterCasePermutation(string S) {
        if (S.size() <= 0) {
            return res_;
        }

        string tmp_str;
        FindSubPermutation(S, 0, tmp_str);

        return res_;
    }

   private:
    void FindSubPermutation(string src_str, int index, string& tmp_string) {
        if (index >= src_str.size()) {
            res_.emplace_back(tmp_string);
        }

        char c = src_str[index];
        if (IsLetter(c)) {
            // 0-->same letter, 1-->change letter
            for (int i = 0; i < 2; ++i) {
                // if (0 == i) {
                //     tmp_string += src_str[i];
                //     FindSubPermutation(src_str, index + 1, tmp_string);
                // }
                if (1 == i) {
                    ChangeLetter(src_str[i]);
                }
                tmp_string += src_str[i];
                FindSubPermutation(src_str, index + 1, tmp_string);
            }
        } else {
            tmp_string += src_str[index];
            FindSubPermutation(src_str, index + 1, tmp_string);
        }
    }

    bool IsLetter(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        } else {
            return false;
        }
    }

    void ChangeLetter(char& c) {
        if (c >= 'a' && c <= 'z') {
            c -= '32';
        }
        if (c >= 'A' && c <= 'Z') {
            c += '32';
        }
        return;
    }
    vector<string> res_;
};

int main(int argc, char* argv[]) {
    string letters = "a1b1";

    Solution sln;
    auto res = sln.letterCasePermutation(letters);

    Utils<string> util;
    util.PrintVector(res);

    return 0;
}