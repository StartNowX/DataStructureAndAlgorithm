/**
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum. input =
 * [-2,1,-3,4,-1,2,1,-5,4], output = 6
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int MaxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int max = nums[0];
    // 联机算法：是在任意时刻算法对要操作的数据只读入（扫描）一次，一旦被读入并处理，它就不需要在被记忆了。而在此处理过程中算法能对它已经读入的数据立即给出相应子序列问题的正确答案
    for(int i = 1; i < nums.size(); ++i) {
        // 如果sum小于0，则其对后续的求和是负增益的
        if(sum < 0) {
            sum = 0;
        }
        sum += nums[i];
        max = max < sum ? sum : max;    
    }

    return max;
}

int MaxSubArrayDP(vector<int>& nums) {
    int result = INT_MIN, f = 0;
    for(int i = 0; i < nums.size(); ++i) {
        f = std::max(f + nums[i], nums[i]);
        result = std::max(result, f);
    }

    return result;
}

int main(int argc, char* argv[]) {
    vector<int> target_vect{-2, -1, -3}; //, 4, -1, 2, 1, -5, 4};

    int length = target_vect.size();
    length = MaxSubArrayDP(target_vect);

    cout << "result: length = " << length << ", elements: ";
    for (vector<int>::iterator it = target_vect.begin();
         it != target_vect.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}