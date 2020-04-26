/**
 * 给定 N，想象一个凸 N 边多边形，其顶点按顺时针顺序依次标记为 A[0], A[i], ..., A[N-1]。

假设您将多边形剖分为 N-2 个三角形。对于每个三角形，该三角形的值是顶点标记的乘积，三角剖分的分数是进行三角剖分后所有 N-2
个三角形的值之和。

返回多边形进行三角剖分后可以得到的最低分。

输入：[1,2,3]
输出：6
解释：多边形已经三角化，唯一三角形的分数为 6。


输入：[3,7,4,5]
输出：144
解释：有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。

输入：[1,3,1,4,1,5]
输出：13
解释：最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 凸多边形形成一个环
    // 对比P96的卡特兰数
    int minScoreTriangulation(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }

        int num = A.size();
        /** dp[i][j]表示从节点i到节点j之间所有三角剖分的最小值
         * dp[i][j] = min{dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]}
         * */
        vector<vector<int> > dp(num, vector<int>(num, INT32_MAX));
        for (int i = 0; i < num; ++i) {
            // 因为形成了一个环，所以通过取余，保证整个环中相邻两个元素是无法构成三角形的
            dp[i][(i + 1) % num] = 0;
        }

        // 枚举所有的长度，从2开始
        for (int len = 2; len < num; ++len) {
            // i代表左起点
            for (int i = 0; i < num; ++i) {
                // j代表右侧终点
                int j = (i + len) % num;
                // k表示从i到j之间的节点，相对于i/j/k三个点构造成一个三角形
                for (int k = (i + 1) % num; k != j; k = (k + 1) % num) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
                }
            }
        }

        return dp[0][num - 1];
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> nums{3, 7, 4, 5};  //{1, 3, 1, 4, 1, 5};

    Solution sln;
    auto res = sln.minScoreTriangulation(nums);

    std::cout << "res = " << res << std::endl;

    return 0;
}