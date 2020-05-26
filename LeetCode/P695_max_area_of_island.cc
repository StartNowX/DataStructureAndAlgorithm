/**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected
4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        m_rows_ = grid.size();
        m_cols_ = grid[0].size();

        direction_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int area = 0;
        for (int i = 0; i < m_rows_; ++i) {
            for (int j = 0; j < m_cols_; ++j) {
                area = std::max(area, GetAreaDfs(grid, i, j));
            }
        }
        return area;
    }

   private:
    int GetAreaDfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m_rows_ || j < 0 || j >= m_cols_ || grid[i][j] == 0) {
            return 0;
        };

        grid[i][j] = 0;
        int area = 1;
        for (auto d : direction_) {
            area += GetAreaDfs(grid, i + d[0], j + d[1]);
        }
        return area;
    }

   private:
    int m_rows_ = 0;
    int m_cols_ = 0;
    vector<vector<int>> direction_;
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    Solution sln;
    auto res = sln.maxAreaOfIsland(grid);
    cout << "res = " << res << endl;

    return 0;
}