/**
 * Given an array of size n, find the majority element. The majority element is
the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist
in the array.

input: [3, 2, 3], output: [3]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MajorityElement(vector<int>& nums) {

    std::sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
}

// 摩尔投票算法
// 知乎@喝七喜
// 摩尔投票算法是基于这个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个
int MajorityElement1(vector<int>& nums) {
    int ret = nums[0];
    int cnt = 1;
    // 这里要注意防止越界
    for (int i = 1; i < nums.size()-1; ++i) {
        if (ret == nums[i]) {
            cnt++;
        } else {
            cnt--;
            if (0 == cnt) {
                ret = nums[i + 1]; // ret更新为下一个元素，i还未更新，保证下一次循环时，ret=nums[i], 以此保证了cnt不会小于0
            }
        }
    }

    return ret;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{3, 2, 3}; //{2, 2, 1, 1, 1, 2, 2};

    int res = MajorityElement1(all_nums);

    cout << "majority element is: " << res << endl;



    return 0;
}