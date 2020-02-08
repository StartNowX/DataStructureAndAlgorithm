/**
 * Given an array of size n, find the majority element. The majority element is
the element that appears more than ⌊ n/3 ⌋ times.

You may assume that the array is non-empty and the majority element always exist
in the array.

input: [3, 2, 3], output: [3]

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 摩尔投票算法
// LeetCode 陈牧远
vector<int> MajorityElement2(vector<int>& nums) {
    int len = nums.size();
    vector<int> res;

    int ret1 = 0;
    int ret2 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < len; ++i) {
        if ((0 == cnt1 || nums[i] == ret1) && nums[i] != ret2) {
            ret1 = nums[i];
            ++cnt1;
        } else if ((0 == cnt2 || nums[i] == ret2)) {
            // && nums[i] != ret1, 加上后面的限制会导致有些序列失败，如[0, -1, 2, -1]，对于[0,0,0]这样的序列最终结果虽然对，但是是在后面遍历的时候做到的
            ret2 = nums[i];
            ++cnt2;
        } else {
            --cnt1;
            --cnt2;
        }
    }

    // cout << "cnt1 = " << cnt1 << ", ret1 = " << ret1 << endl;
    // cout << "cnt2 = " << cnt2 << ", ret2 = " << ret2 << endl;

    int count1 = 0, count2 = 0;
    for (auto num : nums) {
        if (num == ret1) {
            ++count1;
        }
        if (num == ret2) {
            ++count2;
        }
    }

    if (count1 > len / 3) {
        res.emplace_back(ret1);
    }
    // 去重
    if (count2 > len / 3 && ret1 != ret2) {
        res.emplace_back(ret2);
    }

    if (count1 <= len / 3 && count2 <= len / 3) {
        return vector<int>{};
    }

    return res;
}

vector<int> MajorityElement21(vector<int>& nums) {
    int len = nums.size();
    vector<int> res;

    int ret1 = INT32_MAX;
    int ret2 = INT32_MAX;
    int cnt1 = 0;
    int cnt2 = 0;

    // 减cnt的时候，要保证nums[i]不等于给定的两个值
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == ret1) {
            cnt1++;
        } else if (nums[i] == ret2) {
            cnt2++;
        } else if (cnt1 == 0){
            ret1 = nums[i];
            cnt1++;
        } else if (cnt2 == 0){
            ret2 = nums[i];
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    cout << "cnt1 = " << cnt1 << ", ret1 = " << ret1 << endl;
    cout << "cnt2 = " << cnt2 << ", ret2 = " << ret2 << endl;

    int count1 = 0, count2 = 0;
    for(auto num : nums) {
        if (num == ret1) {
            ++count1;
        }
        if (num == ret2) {
            ++count2;
        }

    }

    if (count1 > len / 3) {
        res.emplace_back(ret1);
    }
    // 这里注意去重
    if (count2 > len / 3 && ret1 != ret2) {
        res.emplace_back(ret2);
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{0, -1, 2, -1};//{0, -1, 2, -1};//{0, 0, 0}, {3, 3, 4};  //{1,2,3}; //{}; //{3, 3, 4}; //{2, 2, 1, 1,
                                    //1, 2, 2};  //{3, 2, 3};  //
    vector<int> res;

    res = MajorityElement2(all_nums);

    cout << "majority element is: " << endl;

    for(int i = 0; i < res.size(); ++i) {
        cout << "i = " << i << ", ele = " << res[i] << endl;
    }

    return 0;
}