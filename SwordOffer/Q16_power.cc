/**
 * 实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 *
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 */

#include <iostream>

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        // 特殊case
        if (is_equal(x, 0.0) && n < 0) {
            return 0.0;
        }

        // 幂是负数
        // 处理当n是超过整型范围的数，如-2147483648，因此要先转为unsigned int
        unsigned int ex = static_cast<unsigned int>(n);
        if (n < 0) {
            ex = -ex;
        }

        double result = PowerWithUnsignedExponentEfficient(x, ex);
        if (n < 0) {
            result = 1.0 / result;
        }
        return result;
    }

   private:
    double PowerWithUnsignedExponent(double base, unsigned int exponent) {
        double result = 1.0;

        for (int i = 1; i <= exponent; ++i) {
            result *= base;
        }
        return result;
    }

    // 对于偶数幂，可以分解成已经计算的数的乘积，如2^8，等于2^4乘2^4，而2^4又可以继续分
    // O(logn)
    double PowerWithUnsignedExponentEfficient(double base, unsigned int exponent) {
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return base;
        }

        // 拆分exponent，也是用位运算
        double result = PowerWithUnsignedExponentEfficient(base, exponent >> 1);
        result *= result;

        // 用位运算判断是否为奇数
        if (exponent & 0x01 == 1) {
            result *= base;
        }
        return result;
    }

    // 判断两个数是否相等，不能用(a-b) == 0
    // 计算机内存中表示小数是有误差的
    bool is_equal(double a, double b) {
        if ((a - b) > -0.0000001 && (a - b) < 0.0000001) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char* argv[]) {
    // 1.00000 - 2147483648;
    double x = 2.00000;
    int exponent = 10;

    Solution sln;
    auto res = sln.myPow(x, exponent);
    std::cout << "res = " << res << std::endl;

    return 0;
}