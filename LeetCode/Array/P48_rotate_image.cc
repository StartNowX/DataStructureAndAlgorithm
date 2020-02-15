/**
 * You are given an n x n 2D matrix representing an image. Rotate the image by
 * 90 degrees (clockwise).
 *
 * Note:
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 */

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// 方法1，先上下翻转，再以左对角线翻转
// 方法2，旋转4个矩形，见官方解读
void Rotate(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return;
    }
    // 上下翻转
    int height = matrix.size();
    for (int i = 0; i < height / 2; ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[height - i - 1][j];
            matrix[height - i - 1][j] = tmp;
        }
    }

    // 左对角线翻转
    for (int i = 0; i < height; ++i) {
        // int row = matrix[i].size();
        for (int j = 0; j <= i; ++j) {
            if (i != j) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
    vector<vector<int>> all_nums{
        {5, 1, 9, 1}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    Utils<int> util;
    util.PrintVector2D(all_nums);

    Rotate(all_nums);

    util.PrintVector2D(all_nums);

    return 0;
}