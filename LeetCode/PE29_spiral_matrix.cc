/**
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]] 输出：[1,2,3,6,9,8,7,4,5]
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]] 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 * 0 <= matrix.length <= 100 0 <= matrix[i].length <= 100
 */

// 同54题

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (0 == rows) {
            return vector<int>{};
        }

        int cols = matrix[0].size();
        vector<int> res;
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            // left 还未变化，因此直接从left遍历
            for (int column = left; column <= right; ++column) {
                res.push_back(matrix[top][column]);
            }
            // 下移一行
            for (int row = top + 1; row <= bottom; ++row) {
                res.push_back(matrix[row][right]);
            }

            if (left < right && top < bottom) {
                // 同行往左遍历
                for (int column = right - 1; column > left; --column) {
                    res.push_back(matrix[bottom][column]);
                }
                // 同列往上遍历，上一个循环是column>left就停止了，相当于不包括该行最后一个元素
                for (int row = bottom; row > top; --row) {
                    res.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return res;
    }
};