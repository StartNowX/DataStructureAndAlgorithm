/**
 * 请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是
 * 1。因此，如果输入 9，则该函数输出 2。
 */

#include <iostream>


class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        // 最优解法如下，1存在多少次就只需要移动多少次（也可以设置flag=1，逐步将1左移移位与n位与，将移动N次）
        while (n) {
            ++cnt;
            // n-1能够将最右侧的1变成0，0变成1，再将其与自身位与，则当前位置右侧就全是0了
            n = (n - 1) & n;
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    uint32_t n = 00000000000000000000000000001011;

    Solution sln;
    auto res = sln.hammingWeight(n);
    std::cout << "res = " << res << std::endl;
}