/**
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

    Input: "aba"
    Output: True

    Input: "abca"
    Output: True
    Explanation: You could delete the character 'c'.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool validPalindrome(string s) {
        int low = 0, high = s.length() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return CheckIsValidPalindrom(s, low + 1, high) || CheckIsValidPalindrom(s, low, high - 1);
            }
        }
        return true;
    }

    bool CheckIsValidPalindrom(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) { return 0; }