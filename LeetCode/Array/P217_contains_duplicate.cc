/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the
array, and it should return false if every element is distinct.
 *
 * Input: [1,2,3,1], Output: true
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

// 和P01_sum中的unordered_map的解法类似
bool ContainsDuplicate(vector<int>& nums) {
    std::unordered_map<int, int> num_cnt_pair;

    bool res = false;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (0 == num_cnt_pair.count(*it)) {
            // num_cnt_pair.insert(std::pair<int, int>(*it, 1));
            num_cnt_pair[*it] = 1;
        } else {
            return true;
        }
    }

    return res;
}

// 利用C++的set, 不允许两个元素有相同的键值
bool ContainsDuplicate1(vector<int>& nums) {
    std::set<int> all_num;

    for (auto num : nums) {
        auto it = all_num.insert(num);
        if (!it.second) { // 键值存在，返回false
            return true;
        }
    }

    return all_num.size() != nums.size();
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};  //{}; //{1,2,3,1};
    bool res;

    res = ContainsDuplicate1(all_nums);

    cout << "contains duplicate? " << res << endl;

    return 0;
}