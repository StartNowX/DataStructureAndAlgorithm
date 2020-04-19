/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 卡特兰数
    // G(n)=G(0)∗G(n−1)+G(1)∗G(n−2)+...+G(n−1)∗G(0)
    int numTrees(int n) {
        // dp[i]表示以i为根节点的二叉搜索树的个数
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main(int argc, char* argv[]) { return 0; }