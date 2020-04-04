/**
 * 在一个 n * m
的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/

#include <iostream>
#include <vector>

#include "../utils/include/utils.h"

using namespace std;

class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }

        if (matrix[0].size() == 0) {
            return false;
        }

        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        // 因为二维数组是有序的，所有从右上角开始找，如果右上角的值大于target，则该列全部不会含有target
        int col = cols - 1, row = 0;
        while (col >= 0 && row < rows) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                --col;
            } else {
                ++row;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Utils<int> util_int;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 20;

    Solution sln;
    auto res = sln.findNumberIn2DArray(matrix, target);
    std::cout << "res = " << res << std::endl;

    return 0;
}