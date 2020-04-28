/**
 * Write a program to check whether a given number is an ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Input: 6
Output: true
Explanation: 6 = 2 × 3

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2

Input: 14
Output: false
Explanation: 14 is not ugly since it includes another prime factor 7.
*/

#include <iostream>

using namespace std;

class Solution {
   public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        if (num == 1) {
            return true;
        }

        while (num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }
        // 也可以返回(return num==1)，这样while中就不需要return了
        return true;
    }
};

int main(int argc, char *argv[]) {
    int num = 6;
    Solution sln;
    auto res = sln.isUgly(num);
    std::cout << "res = " << std::boolalpha << res << std::endl;
    return 0;
}