/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water
and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        m_rows_ = grid.size();
        if (0 == m_rows_) {
            return 0;
        }
        m_cols_ = grid[0].size();

        direction_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int cnt = 0;
        for (int i = 0; i < m_rows_; ++i) {
            for (int j = 0; j < m_cols_; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }

   private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i >= 0 && i < m_rows_ && j >= 0 && j < m_cols_ && grid[i][j] == '1') {
            grid[i][j] = '0';
            for (auto d : direction_) {
                dfs(grid, i + d[0], j + d[1]);
            }
        }
    }

    int m_rows_ = 0;
    int m_cols_ = 0;
    vector<vector<int>> direction_;
};

int main(int argc, char* argv[]) {
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};

    Solution sln;
    auto res = sln.numIslands(grid);
    cout << "res = " << res << endl;

    return 0;
}