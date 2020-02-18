/**
 * Given an array, rotate the array to the right by k steps, where k is
non-negative.
 *
 * Input: [1,2,3,4,5,6,7] and k = 3, Output: [5,6,7,1,2,3,4]
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 * Input: [-1,-100,3,99] and k = 2, Output: [3,99,-1,-100]
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 三次旋转，需要考虑k大于数组长度的情况
void rotate(vector<int>& nums, int k){

    int len = nums.size();

    // k等于数组长度时，数组就复原了
    k = k % len;

    // rotate all element
    for (int i = 0; i < len / 2; ++i) {
        int tmp = nums[i];
        nums[i] = nums[len - i - 1];
        nums[len - i - 1] = tmp;
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // rotate first k array
    for (int i = 0; i < k / 2; ++i) {
        int tmp = nums[i];
        nums[i] = nums[k - i - 1];
        nums[k - i - 1] = tmp;
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // rotate the remain element
    int offset = (len - k) / 2;
    for (int i = k; i < k + offset; ++i) {
        int tmp = nums[i];
        nums[i] = nums[len - i + k - 1];
        nums[len - i + k - 1] = tmp;
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{-1}; //{-1, -100, 3, 99};//  {1, 2, 3, 4, 5, 6, 7};
    int k = 2;

    rotate(all_nums, k);

    cout << "majority element is: " << endl;

    for (int i = 0; i < all_nums.size(); ++i) {
        cout << "i = " << i << ", ele = " << all_nums[i] << endl;
    }

    return 0;
}