#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (0 == grid.size()) {
            return 0;
        }

        int row = static_cast<int>(grid.size());
        int col = static_cast<int>(grid[0].size());

        int cnt = 0;

        // 定义四个方向
        vector<int> dr{0, 1, 0, -1};
        vector<int> dc{1, 0, -1, 0};
        // 做减法
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) {
                int value = grid[r][c];
                if (value != 0) {
                    cnt += (value * 6 - 2 * (value - 1));
                }

                int neighbour_min = 0;
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (0 <= nr && nr < row && 0 <= nc && nc < col) {
                        neighbour_min = std::min(value, grid[nr][nc]);

                        cnt -= neighbour_min;
                    }
                }
            }

        return cnt;
    }
};

int main(int argc, char* argv[]) {
    // vector<vector<int>> grid{{2}};
    vector<vector<int>> grid{{1, 2}, {3, 4}};

    Solution sln;
    auto res = sln.surfaceArea(grid);
    std::cout << "res = " << res << std::endl;

    return 0;
}