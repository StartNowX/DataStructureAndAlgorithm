/**
 * Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(1690, 0);
        dp[0] = 1;

        int ulgy;
        /**
         * LeetCode他人解读，官方题解里提到的三个指针p2，p3，p5，但是没有说明其含义，实际上pi的含义是有资格同i相乘的最小丑数的位置。这里资格指的是：如果一个丑数nums[pi]通过乘以i可以得到下一个丑数，那么这个丑数nums[pi]就永远失去了同i相乘的资格（没有必要再乘了），我们把pi++让nums[pi]指向下一个丑数即可。
        https://leetcode-cn.com/problems/ugly-number-ii/solution/san-zhi-zhen-fang-fa-de-li-jie-fang-shi-by-zzxn/
        */
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < 1690; ++i) {
            ulgy = std::min(std::min(dp[i2] * 2, dp[i3] * 3), dp[i5] * 5);
            dp[i] = ulgy;

            if (ulgy == dp[i2] * 2) ++i2;
            if (ulgy == dp[i3] * 3) ++i3;
            if (ulgy == dp[i5] * 5) ++i5;
        }

        return dp[n - 1];
    }

    // 7以上的输入就超时了
    int nthUglyNumber1(int n) {
        int cnt_ugly = 0;
        int num = 0;
        while (cnt_ugly < n) {
            if (isUglyNumber(num)) {
                cnt_ugly++;
                if (cnt_ugly == n) {
                    return num;
                }
            }
            num++;
        }

        return num;
    }

   private:
    bool isUglyNumber(int num) {
        if (num <= 0) {
            return false;
        }

        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            }

            if (num % 3 == 0) {
                num /= 3;
            }

            if (num % 5 == 0) {
                num /= 5;
            }
        }

        return num == 1;
    }
};
int main(int argc, char *argv[]) {
    int num = 10;
    Solution sln;
    auto res = sln.nthUglyNumber(num);
    std::cout << "res = " << res << std::endl;
    return 0;
}