/**
 * Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<string> LetterCombinations(string digits) {
        res_.clear();

        if (0 == digits.size()) {
            return res_;
        }

        string sub_str = "";
        FindCombination(digits, 0, sub_str);
        return res_;
    }

   private:
    void FindCombination(const string& digits, int index,
                         const string& substring) {
        if (index == digits.size()) {
            res_.emplace_back(substring);
        }

        char num = digits[index];
        if (num < '0' || num > '9' || num == '1') {
            return;
        }
        string letters = kLettersMap[num - '0'];

        for (auto letter : letters) {
            FindCombination(digits, index + 1, substring + letter);
        }

        return;
    }

    vector<string> res_;

    const string kLettersMap[10] = {
        " ",     // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz",  // 9
    };
};

int main(int argc, char* argv[]) {
    const string digits = "9";  //"23";

    Solution sln;
    auto res = sln.LetterCombinations(digits);

    Utils<string> util;
    util.PrintVector(res);

    return 0;
}