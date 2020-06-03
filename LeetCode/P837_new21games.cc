/**
 * 爱丽丝参与一个大致基于纸牌游戏 “21点” 规则的游戏，描述如下：

爱丽丝以 0 分开始，并在她的得分少于 K 分时抽取数字。 抽取时，她从 [1, W] 的范围中随机获得一个整数作为分数进行累计，其中
W 是整数。 每次抽取都是独立的，其结果具有相同的概率。

当爱丽丝获得不少于 K 分时，她就停止抽取数字。 爱丽丝的分数不超过 N 的概率是多少？

输入：N = 10, K = 1, W = 10
输出：1.00000
说明：爱丽丝得到一张卡，然后停止。

输入：N = 6, K = 1, W = 10
输出：0.60000
说明：爱丽丝得到一张卡，然后停止。
在 W = 10 的 6 种可能下，她的得分不超过 N = 6 分。

输入：N = 21, K = 17, W = 10
输出：0.73278
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double new21Game(int N, int K, int W) {
        if (0 == K) {
            return 1.0;
        }

        // dp[x]表示以得分X作为开始分数进行抽取，且获胜的概率，如得分小于min(N, K+W-1)，则获胜。K+W-1是能抽取的最大数
        vector<double> dp(K + W + 1);
        // 当K< X <= min(N,K+w-1)时，肯定是获胜的
        for (int i = K; i <= N && i < K + W; ++i) {
            dp[i] = 1.0;
        }

        /** f(x) = 1 / W * (f(x+1) + f(x+2) + f(x+3) + ... + f(x+W))
         *  f(x-1) = 1 / W * (f(x) + f(x+1) + f(x+2) + ... + f(x+W-1) + f(x+W))
         *  可以看到，重复了很多计算
         */
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }

    /**
     * 超时
     */
    double new21GameTimeOut(int N, int K, int W) {
        if (0 == K) {
            return 1.0;
        }

        // dp[x]表示以x为开始分数进行抽取，且获胜的概率，如得分小于min(N, K+W-1)，则获胜。K+W-1是能抽取的最大数
        vector<double> dp(K + W + 1);
        // 在min(N, K+W-1)之间，点数肯定小于N，肯定获胜
        for (int i = K; i <= N && i < K + W; ++i) {
            dp[i] = 1.0;
        }

        for (int i = K - 1; i >= 0; --i) {
            for (int j = 1; j <= W; ++j) {
                dp[i] += dp[i + j] / W;
            }
        }

        return dp[0];
    }
};

int main(int argc, char* argv[]) { return 0; }