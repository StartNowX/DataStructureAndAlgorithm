/**
 * Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is
returned.

*/

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }

        int root = 0;
        for (int i = 0; i <= ceil(x / 2); ++i) {
            // 用long long 防止整型溢出
            if ((long long)(i * i) == x) {
                root = i;
                break;
            }

            if ((long long)(i + 1) * (i + 1) == x) {
                root = i + 1;
                break;
            }

            if ((long long)(i * i) < x && (long long)(i + 1) * (i + 1) > x) {
                root = i;
                break;
            }
        }
        return root;
    }

    // 二分查找
    int mySqrtBS(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;

            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

    /**
     * 实现double类型的平方根
     *
     * 和整型的平方根不同，在停止条件处，需要判断差值是否mid和左右区间的差值是否小于double的精度
     *
     * 注意：
     *  1. 上边界不能是num，当num小于1时，sqrt(num) > num，因此下面取上限时，取的是num+0.25
     *  2. 二分法搜索的停止条件是小于double的精度，而不是随意指定的一个值
     *  3. 由于求的根也会是double类型的，因此每次走的步长不能是int类型的方式（+或-1），下面直接等于mid，
     *      因为left和right都是double类型，每次执行mid = (left + right) / 2时，mid都是不一样的
     *
     * 参考https://blog.csdn.net/xusiwei1236/article/details/25657611
     */
    double sqrt(double num) {
        double left = 0.0, right = num + 0.25, mid;
        for (;;) {
            // while (right - left > 2 * __DBL_EPSILON__) {  // 当m==a或m==b时会死循环
            mid = (left + right) / 2;
            // double的类型精度是DBL_EPSILON，不能随便指定，所以这里是mid-left或right-mid作为判断，保证步长足够小
            if ((mid - left) < __DBL_EPSILON__ || (right - mid) < __DBL_EPSILON__) {
                break;
            }
            if ((mid * mid - num) * (mid * mid - num) < 0) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return mid;
    }
};

int main(int argc, char* argv[]) { return 0; }