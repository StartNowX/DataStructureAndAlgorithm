/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

class Solution {
   public:
    int numWays(int n) {
        // 这里是和菲波那切数列不同的地方，
        if (n <= 1) {
            return 1;
        }

        int stair_1 = 1;
        int stair_2 = 1;
        int total_num = 0;
        // 注意要包含n
        for (int i = 2; i <= n; ++i) {
            total_num = (stair_1 + stair_2) % 1000000007;
            stair_2 = stair_1;
            stair_1 = total_num;
        }
        return total_num;
    }
};


int main(int argc, char* argv[]) {
    Solution sln;
    auto res = sln.numWays(0);

    std::cout << res << std::endl;

    return 0;
}