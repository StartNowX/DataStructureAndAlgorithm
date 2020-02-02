/**
 * 给定两个有序整数数组nums1和nums2，将nums2合并到nums1中，使得num1成为一个有序数组。
 * 说明：
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n；
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2中的元素。
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 输出: [1,2,2,3,5,6]
*/

#include <iostream>
#include <vector>

using namespace std;

// LeetCode 云澈
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int merge_index = m-- + n-- - 1;

    while(m >= 0 && n >= 0) {
        nums1[merge_index--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }

    // nums1 = [0], nums2 = [1], output = [1]
    while(n >= 0) {
        nums1[merge_index--] = nums2[n--];
    }
}

int main(int argc, char* argv[]) {
    vector<int> nums1{1, 9, 11, 0, 0, 0, 0};
    vector<int> nums2{5, 5, 6, 8, 10};

    int len_num1 = 3;
    int len_num2 = 5;

    merge(nums1, len_num1, nums2, len_num2);
    
    int merge_len = len_num1 + len_num2;
    for(int i = 0; i < merge_len; ++i) {
        cout << "i = " << i << ", ele: " << nums1[i] << endl;
    }

    return 0;
}