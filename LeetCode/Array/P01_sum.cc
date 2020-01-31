/**
 * 给定一个整数数组
 * nums 和一个目标值target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。你可以假设每种输入只会对应一个答案。但是，你不能重*
 * 复利用这个数组中同样的元素。 示例: 给定 nums = [2, 7, 11, 15], target = 9
 *  因为 nums[0] + nums[1] = 2 + 7 = 9
 *  所以返回 [0, 1]
 *
 * nums = [3, 2, 4], target = 6
 * nums = [-1, -2, -3, -4, -5], target = -8
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int find(vector<int>& nums, int start_index, int target) {
    if (0 == nums.size()) {
        return -1;
    }

    for (int i = start_index; i < nums.size(); ++i) {
        if (target == nums[i]) {
            return i;
        }
    }
    return -1;
}

// time complexity: O(n), space complexity: O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> all_index;
    size_t length = nums.size();
    if (0 == length) {
        return all_index;
    }
    for (int i = 0; i < length; ++i) {
        int remain = target - nums[i];
        // 这里其实直接两次循环就行了，不需要再封装一个find接口了
        int tmp_index = find(nums, i + 1, remain);
        if (-1 != tmp_index) {
            all_index.push_back(i);
            all_index.push_back(tmp_index);
            return all_index;
        }
        
    }

    return all_index;
}

vector<int> twoSum_hashmap(vector<int>& nums, int target) {
    vector<int> all_index;

    map<int, int> hash_map;
    for (int i = 0; i < nums.size(); ++i) {
        int remain = target - nums[i];
        // not exists, insert into map
        if (0 == hash_map.count(remain)) {
            hash_map.insert(pair<int, int>(nums[i], i));
        } else {
            map<int, int>::iterator it = hash_map.find(remain);
            all_index.push_back(it->second);
            all_index.push_back(i);
            return all_index;
        }
    }
    return all_index;
}

// unordered_map比map速度会快很多，两者的区别参考https://blog.csdn.net/batuwuhanpei/article/details/50727227
vector<int> twoSum_hashmap1(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int complement = target - nums[i];
        if (record.find(complement) != record.end()) {
            return vector<int>{record[complement], i};
        }
        record[nums[i]] = i;
    }
    return vector<int>{};
}

int main(int argc, char* argv[]){

    // vector<int> nums{3, 0, 5, 11, 9};
    // vector<int> nums{3, 2, 4}; // 6
    vector<int> nums{-1, -2, -3, -4, -5}; // target = -8 
    int target = -8;

    vector<int> res_index;
    // res_index = twoSum(nums, target);
    res_index = twoSum_hashmap1(nums, target);

    for(vector<int>::iterator it = res_index.begin(); it != res_index.end(); ++it){
        cout << "*it = " << *it << std::endl;
    }

    return 0;
}