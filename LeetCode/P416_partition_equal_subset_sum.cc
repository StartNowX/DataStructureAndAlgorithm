/**
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Each of the array element will not exceed 100.
The array size will not exceed 200.

Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (0 == nums.size()) {
            return false;
        }

        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;

        // 背包中应该放的容量
        int target = sum / 2;
        // 行：元素索引，列，背包中的容量，target+1表示考虑0元素
        // dp[i][j]表示从0-i区间选取一些元素其和能等于j
        vector<vector<int>> dp(nums.size(), vector<int>(target+1));
        if (nums[0] < target) {
            dp[0][0] = false;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j];

                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }

                if (nums[i] < j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[nums.size()-1][target];

    }

    bool canPartitionBetter(vector<int>& nums) {
        if (0 == nums.size()) {
            return false;
        }

        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;

        // 背包中应该放的容量
        int target = sum / 2;
        // 状态压缩
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) 
            for (int j = target; j >= 0; j--) 
                if (j - nums[i] >= 0) 
                    dp[j] = dp[j] || dp[j - nums[i]];

        return dp[target];
};

int main(int argc, char *argv[]) {
    return 0;
}