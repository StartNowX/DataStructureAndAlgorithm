/**
 * Given an array nums, write a function to move all 0's to the end of it while
maintaining the relative order of the non-zero elements.
 *
 * Input: [0,1,0,3,12], Output: [1,3,12,0,0]
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
*/

#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

// 从数值首位往后依次存放非零数据，最后非零数值后的所有数全部置零
void MoveZeroes(vector<int>& nums) {

    int len = nums.size();
    // 记录当前填充了非零数据的位置
    int cur_non_zero_index = 0;

    for (int i = 0; i < len; ++i) {
        if(0 != nums[i]) {
            nums[cur_non_zero_index] = nums[i];
            cur_non_zero_index++;
        }
    }

    for (int i = cur_non_zero_index; i < len; ++i) {
        nums[i] = 0;
    }

    /* 这种方式不需要最后的置零操作，每次将非零的数据和0进行交换
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            ++j;
        }
    } */
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{0, 1,1,1,1,1}; //{0, 1, 0, 3, 12, 0, 9, 0, 0, 0};

    Utils<int> util;
    util.PrintVector(all_nums);

    MoveZeroes(all_nums);

    util.PrintVector(all_nums);

    return 0;
}