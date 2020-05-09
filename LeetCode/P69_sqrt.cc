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
};

int main(int argc, char* argv[]) { return 0; }