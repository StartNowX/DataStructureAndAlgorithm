/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element
in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it
impossible to reach the last index.

    1 <= nums.length <= 3 * 10^4
    0 <= nums[i][j] <= 10^5
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (0 == len) {
            return 0;
        }

        // 每跳一次都记录一次该点之前能跳的最远位置，如果超过了最远位置，就表明不能跳到最终点
        int max_pos = 0;
        for (int i = 0; i < len; ++i) {
            if (i > max_pos) {
                return false;
            }
            max_pos = std::max(max_pos, i + nums[i]);
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{3, 2, 1, 1, 4};  //{2, 3, 1, 1, 4};

    Solution sln;
    auto res = sln.canJump(nums);

    std::cout << "res = " << std::boolalpha << res << std::endl;

    return 0;
}