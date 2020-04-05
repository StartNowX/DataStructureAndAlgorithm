/**
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999
 *
 * 输入: n = 1
 * 输出: [1,2,3,4,5,6,7,8,9]
 */

#include <algorithm>
#include <iostream>
#include <vector>

#include "../utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for (int i = 0; i < pow(10, n); ++i) {
            res.emplace_back(i);
        }

        return res;
    }

    // 用string处理
    vector<int> printNumbersMaxValue(int n) {
        if (n <= 0) {
            return res_;
        }

        std::string number(n, '0');
        while (!Increasement(number)) {
            SaveNumbers(number);
        }

        return res_;
    }

   private:
    bool Increasement(std::string& number) {
        bool is_overflow = false;  // 是否越界（到达最大值）
        int is_takeover = 0;       // 是否进位
        int len = number.length();

        for (int i = len - 1; i >= 0; --i) {
            int sum = number[i] - '0' + is_takeover;

            if (i == len - 1) {
                // 字符串的最后一位，则对数字加1
                sum++;
            }

            // 当前位出现进位了
            if (sum >= 10) {
                // i为0时，表明字符串第0位，达到最大值了
                if (i == 0) {
                    is_overflow = true;
                } else {
                    is_takeover = 1;
                    number[i] = sum - 10 + '0';
                }
            } else {
                is_takeover = 0;
                number[i] = sum + '0';
                break;
            }
        }
        return is_overflow;
    }

    void SaveNumbers(std::string number) {
        std::string tmp_str(number.size(), '0');
        if (tmp_str == number) {
            return;
        }
        res_.emplace_back(stoi(number));
    }

    std::vector<int> res_;
};


int main(int argc, char* argv[]) {
    int n = 2;

    Solution sln;
    auto res = sln.printNumbers(n);

    Utils<int> utils_int;
    utils_int.PrintVector(res);
    // std::cout << "res = " << res << std::endl;

    return 0;
}