/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto num : nums) {
            num_set.insert(num);
        }

        int longest_length = 0;
        for (auto num : nums) {
            // 连续序列不包含重复的元素
            if (!num_set.count(num - 1)) {
                int cnt = 1;
                int curr_num = num;

                // 一直去找下一个元素
                while (num_set.count(curr_num + 1)) {
                    curr_num += 1;
                    cnt += 1;
                }

                longest_length = max(longest_length, cnt);
            }
        }

        return longest_length;
        /**
         * bad case [1,2,0,1]
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        int length = nums.size();
        if (length == 1) {
            return 1;
        }
        int max_cnt = 0;
        while (left < right && right < length) {
            int last_ele = nums[left];
            int cnt = 1;
            while (right < length && nums[right] - last_ele >= 1) {
                last_ele = nums[right];
                right++;
                cnt++;
            }
            max_cnt = max(max_cnt, cnt);
            left++;
        }
        return max_cnt;
        */
    }
};