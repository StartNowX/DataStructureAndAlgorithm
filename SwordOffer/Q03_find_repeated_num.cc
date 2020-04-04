/**
 * 找出数组中重复的元素
 */
#include <iostream>
#include <unordered_set>
#include <vector>

#include "../utils/include/utils.h"

using namespace std;

class Solution {
   public:
    // 需要额外的空间
    int findRepeatNumber(vector<int>& nums) {
        std::unordered_set<int> all_set;
        for (auto& n : nums) {
            if (all_set.find(n) != all_set.end()) {
                return n;
            } else {
                all_set.insert(n);
            }
        }
        return -1;
    }

    // 原地操作
    // 将每个下标和数字对应起来
    int findRepeatNumberInPlace(vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            while (nums[i] != i) {
                int tmp = nums[i];
                if (nums[tmp] == tmp) return tmp;
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    vector<int> eles{6, 3, 1, 0, 2, 5, 3};


    Solution sln;
    auto res = sln.findRepeatNumberInPlace(eles);

    std::cout << "res = " << res << std::endl;

    return 0;
}