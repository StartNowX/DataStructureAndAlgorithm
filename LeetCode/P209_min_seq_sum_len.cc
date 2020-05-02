/**
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of
which the sum ≥ s. If there isn't one, return 0 instead.

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (0 == len) {
            return 0;
        }

        int start = 0, sum = 0;
        int min_len = INT32_MAX;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];

            // 滑动窗长度要在while中计算，如果在外面计算，因为是取最小值，可能会被其他未满足条件但是值很小的滑动窗的长度替代
            while (sum >= s) {
                min_len = std::min(min_len, i - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return min_len == INT32_MAX ? 0 : min_len;
    }
};

int main(int argc, char* argv[]) { return 0; }