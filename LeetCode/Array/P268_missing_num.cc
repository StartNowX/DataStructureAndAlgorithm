/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
the one that is missing from the array.
 * Input: [3,0,1], Output: 2
 * Input: [9,6,4,2,3,5,7,0,1], Output: 8
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MissingNumberSum(vector<int>& nums) {
    // 这种方式当N足够大时sum整型溢出的可能,
    // 借鉴LeetCode yycoder的做法，边加边减, 计算最后的差值
    // int len = nums.size();
    int sum = 0;
    int i = 0;
    for(auto num : nums) {
        sum += num - i;
        i++;
    }

    // int res = len * (len + 1) / 2 - sum;
    sum -= i;
    return abs(sum);
}

int MissingNumberSort(vector<int>& nums) {
    int len = nums.size();

    if (0 == len) {
        return 0;
    }

    if ((1 == len) && 1 != nums[0]) {
        return 1;
    }

    // 排序
    std::sort(nums.begin(), nums.end());

    // 繁琐的做法，如果是排序的话，直接排序完从首位开始分别和0,1,2,...进行比较就行了，最后返回不相等的那一位+1的结果
    if (len != nums[len - 1]) {
        return len;
    }

    if (0 != nums[0]) {
        return 0;
    }

    int last_num = 0;
    for (int i = 1; i < len; ++i) {
        if (nums[i] != last_num + 1) {
            return last_num + 1;
        }
        last_num = nums[i];
    }

    return 0;
}

// LeetCode 陈牧远, 使用异或操作
int MissingNumberBitOperator(vector<int>& nums) {
    // res等于最大应该存在的值，不能等于0，如[0, 1], 缺失的是2
    int res = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        res ^= nums[i];
        // 这里再和i异或，最终整个序列下来，存在的数字相当于抵消了，4^4=0, 0^4=4
        res ^= i;
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{0, 1}; //{3, 0, 1}; //{0}; //{9, 6, 4, 2, 3, 5, 7, 0, 1};  //{3, 2, 1};  //{}; //{1,2,3,1};
    int res;

    res = MissingNumberSum(all_nums);

    cout << "contains duplicate? " << res << endl;

    return 0;
}