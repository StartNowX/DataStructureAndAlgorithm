/**
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0]
的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格
[35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 
输入：m = 2, n = 3, k = 1
输出：3

输入：m = 3, n = 1, k = 0
输出：1

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int movingCount(int m, int n, int k) {
        if (m == 0 || n == 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }

        used = vector<vector<int>>(m, vector<int>(n, 0));
        int cnt = longest_sub_path(m, n, 0, 0, k);
        // return的结果要加1，因为后面没有考虑[0,0]这个位置
        return cnt + 1;
    }

   private:
    int longest_sub_path(int m, int n, int x, int y, int k) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return 0;
        }

        if (bit_sum(x, y) > k) {
            return 0;
        }

        used[x][y] = 1;

        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            int new_x = x + x_shift[i];
            int new_y = y + y_shift[i];

            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !used[new_x][new_y] &&
                (bit_sum(new_x, new_y) <= k)) {
                cnt += (1 + longest_sub_path(m, n, new_x, new_y, k));
                // std::cout << "x = " << new_x << ", y = " << new_y << ", bit_sum = " << bit_sum(new_x, new_y)
                //           << ", cnt = " << cnt << std::endl;
            }
        }
        return cnt;
    }

    int bit_sum(int x, int y) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        while (y > 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }

    // left, right, up, down
    vector<int> x_shift{-1, 1, 0, 0};
    vector<int> y_shift{0, 0, -1, 1};
    vector<vector<int>> used;
};

int main(int argc, char* argv[]) {
    Solution sln;

    auto res = sln.movingCount(1, 5, 10);
    std::cout << "res = " << res << std::endl;


    return 0;
}