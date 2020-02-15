/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with
 * x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 *
 * Input: [1,8,6,2,5,4,8,3,7] Output: 49
 * */

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int MaxArea(vector<int>& height) {
    if (height.size() < 2) {
        return 0;
    }

    /** 两次循环遍历，超过时间限制
    int area = 0, tmp_area = 0;
    int small_height = height[0];
    for (int i = 0; i < height.size(); ++i) {
        for (int j = 0; j < height.size(); ++j) {
            small_height = height[i] < height[j] ? height[i] : height[j];
            tmp_area = small_height * (j - i);
            area = tmp_area > area ? tmp_area : area;
        }
    }*/

    // LeetCode ChengMing
    // Area = Max(min(height[i], height[j]) * (j-i)) {其中0<=i<j<height.size()}
    // 双指针方法，使用两个指针从数组收尾分别移动，值小的向内移动，如果值大的向内移动，则受限于较小值的影响，两者之间的面积不会有所增加
    if (height.size() <= 1) {
        return 0;
    }
    int left_index = 0, right_index = height.size() - 1;
    int area = 0, tmp_area;
    while (left_index < right_index) {
        tmp_area = MIN(height[left_index], height[right_index]) *
                   (right_index - left_index);
        area = MAX(tmp_area, area);
        // 只关注最大的面积而不关注产生最大面积对应的左右坐标，因此不用考虑如果变化左右坐标
        if (height[left_index] < height[right_index]) {
            left_index++;
        } else {
            right_index--;
        }
    }

    return area;
}

int main(int argc, char* argv[]) {
    vector<int> all_nums{1, 8, 6, 2, 5, 4, 8, 3, 7};

    Utils<int> util;
    util.PrintVector(all_nums);

    int res = MaxArea(all_nums);

    cout << "most water is: " << res << endl;

    util.PrintVector(all_nums);

    return 0;
}