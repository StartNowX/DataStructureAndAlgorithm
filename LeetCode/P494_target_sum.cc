/**
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For
each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findTargetSumWaysDP(vector<int>& nums, int S) {
        if (nums.size() == 0 && S != 0) {
            return 0;
        }
        if (nums.size() == 0) {
            return 0;
        }

        // 数组和不超过1000，因此正负总共2001个元素
        vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
        // 之所以加上1000，是因为数组下标不能为负数
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;

        for (int i = 1; i < nums.size(); ++i) {
            // 当前总和从-1000开始，最小值
            for (int j = -1000; j <= 1000; ++j) {
                if (dp[i - 1][j + 1000] > 0) {
                    dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000];
                    dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000];
                }
            }
        }

        return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];
    }

    int findTargetSumWaysRecursive(vector<int>& nums, int S) {
        if (nums.size() == 0 && S != 0) {
            return 0;
        }
        if (nums.size() == 0) {
            return 0;
        }

        CalculateNextEle(nums, 0, 0, S);

        return count_;
    }

   private:
    void CalculateNextEle(vector<int>& nums, int index, int sum, int S) {
        if (index == nums.size()) {
            if (sum == S) {
                count_++;
            }
            return;
        }

        // 递归遍历
        CalculateNextEle(nums, index + 1, sum + nums[index], S);
        CalculateNextEle(nums, index + 1, sum - nums[index], S);
        return;
    }

    int count_ = 0;
};

int main(int argc, char* argv[]) {
    vector<int> nums{1, 1, 1, 1, 1};
    int S = 3;

    Solution sln;
    auto res = sln.findTargetSumWaysDP(nums, S);
    std::cout << "res = " << res << std::endl;

    return 0;
}