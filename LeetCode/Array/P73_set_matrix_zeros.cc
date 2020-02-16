/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 Do it in-place.

    Input:
    [
      [1,1,1],
      [1,0,1],
      [1,1,1]
    ]
    Output:
    [
      [1,0,1],
      [0,0,0],
      [1,0,1]
    ]

Follow up:
1. A straight forward solution using O(mn) space is probably a bad idea.
2. A simple improvement uses O(m + n) space, but still not the best solution.
3. Could you devise a constant space solution?

*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// time complexity: O(m*n), space complexity O(1)
// 先找矩阵中为零的坐标，将该坐标对应的行和列中不为0的数全部置为一个虚拟值，然后再遍历矩阵，将所有等于虚拟值的数替换为0
void SetZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (0 == m) {
        return;
    }

    int n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (0 == matrix[i][j]) {
                for (int k = 0; k < n; ++k) {
                    matrix[i][k] = (0 == matrix[i][k]) ? 0 : -10000000;
                }

                for (int k = 0; k < m; ++k) {
                    matrix[k][j] = (0 == matrix[k][j]) ? 0 : -10000000;
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (-10000000 == matrix[i][j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

// 方法2，用每行和每列的首位标记此行或此列是否需要修改
void SetZeroesFast(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (0 == rows) {
        return;
    }

    int cols = matrix[0].size();

    bool first_col_marked = false;
    bool first_row_marked = false;
    // 第一行
    for (int i = 0; i < cols; ++i) {
        if (0 == matrix[0][i]) {
            first_col_marked = true;
            break;
        }
    }

    // 第一列
    for (int i = 0; i < rows; ++i) {
        if (0 == matrix[i][0]) {
            first_row_marked = true;
            break;
        }
    }

    // 从第二行第二列开始遍历，如果数为0，则其对应的行首、列首被置为0
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (0 == matrix[i][j]) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // 检查第一行，为0，则更新整列（注意是从第一行第二列开始的）
    for (int i = 1; i < cols; ++i) {
        if (0 == matrix[0][i]) {
            for (int j = 0; j < rows; ++j) {
                matrix[j][i] = 0;
            }
        }
    }

    // 检查第一列，为0，则更新整行（注意是从第一列第二行开始的，不然第一行可能在上一步已经被全部置为0，导致这一步会把整个数组置为0）
    for (int i = 1; i < rows; ++i) {
        if (0 == matrix[i][0]) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // 因为找为0的元素的遍历是从第二行第二列开始的，因此要对第一行，第一列中是否有0的数据进行处理
    // 就matrix[0][0]这个数是否被标记了，即, matrix[0][0]这个数是否为0；
    // 如果是第一行或第一列的其他位置为0，即便没有标记first_col_marked或first_row_marked,
    // 上两步就都能将其对应的行和列处理过了
    if (first_col_marked) {
        for (int i = 0; i < cols; ++i) {
            matrix[0][i] = 0;
        }
    }

    if (first_row_marked) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
}

int main(int argc, char* argv[]) {
    // {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> all_nums{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    Utils<int> util;
    util.PrintVector2D(all_nums);

    SetZeroesFast(all_nums);

    util.PrintVector2D(all_nums);

    return 0;
}