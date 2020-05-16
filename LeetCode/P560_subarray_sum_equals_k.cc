/**
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum
equals to k.

Input:nums = [1,1,1], k = 2
Output: 2

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }

        /**每次找以i为结尾的所有元素和为k的数组个数
         * pre[i] - pre[j-1] == k，也就是pre[j-1] == pre[i] -k，也就是当结尾元素是i时，统计其能组成的和为k的数组个数，
         * 也就是统计前缀中有多少pre[j-1](即pre[i] - k)
         *
         * 构造一个map，和为key，次数为value
         */
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, pre = 0;
        for (auto x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) cnt += mp[pre - k];
            mp[pre]++;
        }
        return cnt;
    }

    /**
     * 枚举，O(n^2), 超时
     */
    int subarraySumDoubleFor(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }

        long sum = 0;
        int cnt = 0;
        for (int start = 0; start < nums.size(); ++start) {
            sum = nums[start];
            for (int end = start; end < nums.size(); ++end) {
                sum += nums[end];
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    /**
     * 没想到如何处理负数 [-1, -2, -5, 1,1,1,2,3,4] k=3
     */
    int subarraySumWrong(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }

        int start = 0, end = 0;
        long sum = 0;
        int cnt = 0;
        while (end <= nums.size() && start < nums.size()) {
            while (end < nums.size() && sum < k) {
                sum += nums[end];
                end++;
            }

            if (sum == k) {
                cnt++;
            }

            sum -= nums[start];
            start++;
        }

        return cnt;
    }
};

int main(int argc, char* argv[]) { return 0; }