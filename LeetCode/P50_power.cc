/**
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 *
 * Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


notes:
    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 */

// 同SwordOffer的Q16_power.cc

#include <iostream>
class Solution {
   public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        // 由于题中指定n是一个signed integer，因此这里需要转换
        unsigned int abs_n = static_cast<unsigned int>(n);
        // 同时，注意这里判断n是否为负数时，还是用n
        if (n < 0) {
            abs_n = -abs_n;
        }

        double res = myPowCore(x, abs_n);
        if (n < 0) {
            return double(1) / (res + 1e-32);
        } else {
            return res;
        }
    }

    double myPowCore(double x, unsigned int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        double res = myPowCore(x, n >> 1);
        res *= res;

        if (n & 1 == 1) {
            res *= x;
        }

        return res;
    }
};