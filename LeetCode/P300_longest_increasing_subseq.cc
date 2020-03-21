/**
 *Given an unsorted array of integers, find the length of longest increasing subsequence.

    Input: [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexit

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 贪心算法+二分查找，O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        // 数组d[i]表示长度为i的最长上升子序列的末尾元素的最小值
        int len = 1, n = (int)nums.size();

        if (0 == n) return 0;

        vector<int> d(n + 1, 0);
        d[len] = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len])
                d[++len] = nums[i];
            else {
                // 找d前面可以插入nums[i]的位置
                int l = 1;
                int r = len;
                int pos = 0;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (nums[i] > d[mid]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }

        return len;
    }

    // DP，O(n^2)，空间复杂度O(n)
    int lengthOfLISDP(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        vector<int> dp(nums.size(), 0);

        /**
         * 题目要求，不一定是连续的升序，因此dp[i]需要和dp[0],dp[1]...dp[i-1]比较
         * 处理不了{4, 10, 4, 3, 8, 9};这样的情况
        for (int i = 1; i < nums.size(); ++i) {
            int tmp_max = 0;
            int last_max_value = nums[0];
            for (int j = 0; j < i; ++j) {
                // tmp_max = std::max(tmp_max, dp[j]);
                if (dp[j] >= tmp_max) {
                    tmp_max = dp[j];
                    last_max_value = nums[j];
                } else {
                    // last_max_value
                }
            }

            // 严格升序，等于不算
            dp[i] = nums[i] > last_max_value ? tmp_max + 1 : tmp_max;
            std::cout << "num = " << nums[i] << ", last_max_value = " << last_max_value << ", dp: " << dp[i]
                        << std::endl;
        }*/

        // dp[i]表示以第i个数结尾的最长上升子序列的长度
        // 因此，最终整个数组的最长上升子序列是所有dp中的最大值
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                // 不需要像上面的代码想复杂了，因为对于i会和i前的所有元素比较，
                // 而i前的两个元素之间的大小，因为是自底向下的，所以i前的两个元素之间其实已经比较过了，并将结果存放于对应的dp数组中了
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return max_vec_element(dp);
    }

   private:
    int max_vec_element(const vector<int>& vec) {
        int max = vec[0];
        for (auto& v : vec) {
            max = v > max ? v : max;
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    // {2, 2};  //{10, 1, 200, 9, 2, 5, 3, 7, 101, 18}; {4, 10, 4, 3, 8, 9}
    // {10, 9, 2, 5, 3, 7, 101, 18};  //{1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> input{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};

    Solution sln;
    auto res = sln.lengthOfLIS(input);
    std::cout << "res = " << res << std::endl;

    return 0;
}