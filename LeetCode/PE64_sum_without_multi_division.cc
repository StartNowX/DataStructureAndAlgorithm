/**
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 *
 * 示例 1：
    输入: n = 3
    输出: 6

    示例 2：
    输入: n = 9
    输出: 45
*/

#include <iostream>

using namespace std;

class Solution {
   public:
    /**
     * O(n): 利用&&的特性，A&&B，如果A为真，就不会执行B
     */
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }

    /**
     * O(logn)
     */
    int sumNumsFast(int n) {}
};

int main(int argc, char* argv[]) { return 0; }