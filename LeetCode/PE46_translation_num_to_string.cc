/**
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成
“z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
    输入: 12258
    输出: 5
    解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int translateNum(int num) {
        std::string str_num = std::to_string(num);
        // 考虑有效的数字索引范围是0-25，因此对于一个位置i的翻译次数，其只只可能是之前的i-1和i-2两个位置的翻译次数有关，类似打家劫舍问题
        // 转成dp的状态转移方程是：f(i)=f(i-1) + f(i-2)(10 <= i <=
        // 25)，因为只和前两个元素有关，所以可以用滚动数组的方式实现，f(-1)=0, f(0)=1
        int pre_2 = 0, pre_1 = 0, cur = 1;
        for (int i = 0; i < str_num.size(); ++i) {
            pre_2 = pre_1;
            pre_1 = cur;
            cur = 0;
            cur += pre_1;  // f(i) + f(i - 1)
            if (0 == i) {
                continue;
            }

            auto pre = str_num.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {
                cur += pre_2;  // f(i) + f(i - 2)
            }
        }

        return cur;
    }
};