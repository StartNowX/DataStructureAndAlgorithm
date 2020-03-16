/**
 * Implement a method to perform basic string compression using the counts of repeated characters. For example, the
string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string,
your method should return the original string. You can assume the string has only uppercase and lowercase letters (a -
z).

Input: "aabcccccaaa" Output: "a2b1c5a3"

Input: "abbccd"
Output: "abbccd"
Explanation:
The compressed string is "a1b2c2d1", which is longer than the original string.
*/

#include "utils/include/utils.h"
#include "utils/include/time_log.h"
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string compressString(string S) {
        std::string res;
        if (0 == S.size()) {
            return res;
        }

        if (1 == S.size()) {
            return S;
        }

        char tmp = S[0];
        int cnt = 1;
        for (int i = 1; i < S.size(); ++i) {
            std::cout << "i = " << i << ", S[i] = " << S[i] << ", tmp = " << tmp << ", res = " << res << std::endl;
            if (S[i] == tmp) {
                cnt++;
            } else {
                res += tmp;
                res += std::to_string(cnt);

                tmp = S[i];
                cnt = 1;
            }
            if (i == S.size() - 1) {
                if (S[i] == tmp) {
                    // cnt++;
                    res += tmp;
                    res += std::to_string(cnt);
                } else {
                    res += S[i];
                    res += std::to_string(1);
                }
            }
        }
        if (res.size() >= S.size()) {
            return S;
        }
        return res;
    }

    string compressString_better(string S) {
        string res = "";
        if (S.size() == 0) {
            return res;
        }

        int cnt = 1;
        char tmp = S[0];
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == tmp) {
                cnt++;
            } else {
                res += tmp + std::to_string(cnt);

                tmp = S[i];
                cnt = 1;
            }
        }
        // 通过这最后一句就能够处理边界条件，如最后一个字符和前一个不等，或者字符串只有一个字符
        res += tmp + std::to_string(cnt);

        if (res.size() >= S.size()) {
            return S;
        } else {
            return res;
        }
    }

    // 快慢指针
    string compressStringDoublePointer(string S) {
        int N = S.length();
        string res;
        int i = 0;
        while (i < N) {
            int j = i;
            while (j < N && S[i] == S[j]) {
                j++;
            }
            res += S[i];
            res += std::to_string(j - i);
            i = j;
        }

        if (res.length() >= S.length()) {
            return S;
        } else {
            return res;
        }
    }
};

int main(int argc, char* argv[]) {
    //"aabcccccaaa"   "abbccd" "aabcccccaaa" "bb"
    std::string input = "aabcccccaaa";

    Solution sln;
    std::string res;

    {
        TimeLog scope("compress_string");
        res = sln.compressStringDoublePointer(input);
    }
    std::cout << "res = " << res << std::endl;

    return 0;
}