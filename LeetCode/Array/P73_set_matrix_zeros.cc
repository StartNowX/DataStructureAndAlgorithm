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

int main(int argc, char* argv[]) {
    vector<vector<int>> all_nums{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    Utils<int> util;
    util.PrintVector2D(all_nums);

    SetZeroes(all_nums);

    util.PrintVector2D(all_nums);

    return 0;
}