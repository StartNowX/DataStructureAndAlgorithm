/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element
in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

    Input: [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2.
        Jump 1 step from index 0 to 1, then 3 steps to the last index.

    Note:
        You can assume that you can always reach the last index.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // timeout
    int jumpDP(vector<int>& nums) {
        int len = nums.size();
        if (0 == len) {
            return 0;
        }

        vector<int> dp(len, len + 1);
        // 第0个位置的步数是0不是1
        dp[0] = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                // 每个nums[j]代表的是所能跳的步数的最大值，因此满足i-j<=nums[j]的都是有效范围
                if (i - j <= nums[j]) dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }

        return dp[len - 1];
    }

    /**
     * 贪心算法，一步一步跳，遍历数组，每次记录当前能够达到的最大边界，当到达边界时，增加步数
     */
    int jumpGreedy(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return 0;
        }

        // 最后一个元素不需要算，因为边界肯定大于等于最后一个元素的位置，当边界正好是最后一个元素时，会增加一次访问的步数
        int max_pos = 0, end = 0, cnt = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (max_pos >= i) {
                max_pos = std::max(max_pos, i + nums[i]);
                if (i == end) {
                    end = max_pos;
                    ++cnt;
                }
            }
        }
        return cnt;
    }

    // 复杂化，还不能处理所有case
    int jumpGreedyWrong(vector<int>& nums) {
        int len = nums.size();
        if (0 == len) {
            return 0;
        }

        int i = 0;
        int cnt = 0;
        while (i < len) {
            int target_index = 0;
            int max_value = 0;
            for (int j = i; j < i + nums[i] && j < len; ++j) {
                if (nums[j] > max_value) {
                    max_value = nums[j];
                    target_index = j;
                }
                if (target_index + max_value == len - 1) {
                    break;
                }
            }

            target_index = (target_index == 0) ? 1 : target_index;
            i += target_index;
            cnt++;
            if (i + nums[i] == len - 1) {
                return cnt + 1;
            }
        }

        return cnt;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{2, 3, 0, 1, 4};  //{2, 3, 1, 1, 4};

    Solution sln;
    auto res = sln.jumpGreedy(nums);

    std::cout << "res = " << res << std::endl;

    return 0;
}