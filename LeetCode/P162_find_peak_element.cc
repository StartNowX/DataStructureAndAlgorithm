/**
 * A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

    Input: nums = [1,2,1,3,5,6,4]
    Output: 1 or 5
    Explanation: Your function can return either index number 1 where the peak element is 2,
                 or index number 5 where the peak element is 6.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 通过二分查找法，按升序往右找，找到最右边，肯定是一个峰值
    int findPeakElement(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        if (0 == len) {
            return 0;
        }

        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // 如果在while没有return，那么left+1<right已经不满足了，所以就需要对nums[left]和nums[right]比较了
        if (nums[left] > nums[right]) {
            return left;
        }
        return right;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{1, 2, 1, 5, 6, 4};

    Solution sln;
    auto res = sln.findPeakElement(nums);

    std::cout << "res = " << res << std::endl;

    return 0;
}