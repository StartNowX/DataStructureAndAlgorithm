/**
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has
the largest product.

    Input: [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.

    Input: [-2,0,-1]
    Output: 0
    Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        int max = INT8_MIN, imax = 1, imin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            // 当nums[i]是负数，则乘上这个值之后，之前的最大值会变为最小值，最小值则变为最大值，因此这里要交换一下
            // 区别于P300_longest_increasing_subseq.cc
            if (nums[i] < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }

            imax = std::max(imax * nums[i], nums[i]);
            imin = std::min(imin * nums[i], nums[i]);

            max = std::max(max, imax);
        }

        return max;
    }

    /* bad cases
     int maxProduct(vector<int>& nums) {
         if (0 == nums.size()) {
             return 0;
         }

         int n = nums.size();
         vector<int> dp(n, INT8_MIN);
         dp[0] = nums[0];
         // 这种做法的bad case是没有正确处理两个负数的问题，如[2,3,-2,-4],按这个思路算的话，返回的是6
         for (int i = 1; i < n; ++i) {
             if (dp[i - 1] <= dp[i - 1] * nums[i]) {
                 dp[i] = dp[i - 1] * nums[i];
             }
             if (dp[i - 1] * nums[i] <= nums[i]) {
                 dp[i] = nums[i];
             }
         }

         return GetMax(dp);
     }
     */

    int GetMax(const std::vector<int>& nums) {
        int max = nums[0];
        for (auto& n : nums) {
            max = max < n ? n : max;
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    // {2, 3, -2, 4}  {-2, 0, -1}  {1, 0, -1, 2, 3, 4, -2, 10, 4}
    vector<int> vec{1, 0, -1, 2, 3, 4, -2, 10, 4};

    Solution sln;
    auto res = sln.maxProduct(vec);
    std::cout << "res = " << res << std::endl;

    return 0;
}