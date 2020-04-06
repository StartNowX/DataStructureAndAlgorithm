/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子

同LeetCode的P79_word_search.cc
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }

        bool res = false;
        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        row_max_ = rows;
        col_max_ = cols;

        int index = 0;
        std::cout << row_max_ << " " << col_max_ << std::endl;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                res = IsNeighbours(board, word, r, c, index);
                if (res) {
                    return true;
                }
            }
        }
        return res;
    }


   private:
    bool IsNeighbours(vector<vector<char>>& board, string word, int x, int y, int index) {
        if (x < 0 || x >= row_max_ || y < 0 || y >= col_max_) {
            return false;
        }

        if (word[index] != board[x][y]) {
            return false;
        }

        if (index == word.length() - 1) {
            return true;
        }

        char tmp = board[x][y];
        board[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int new_x = x + x_shift_[i];
            int new_y = y + y_shift_[i];
            if (new_x >= 0 && new_x < row_max_ && new_y >= 0 && new_y < col_max_) {
                if (IsNeighbours(board, word, new_x, new_y, index + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = tmp;
        return false;
    }

    int col_max_;
    int row_max_;
    vector<int> x_shift_{-1, 1, 0, 0};
    vector<int> y_shift_{0, 0, -1, 1};
};

int main(int argc, char* argv[]) {
    vector<vector<char>> board{{'a', 'b'}};  //{{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    string target = "ab";

    Solution sln;
    auto res = sln.exist(board, target);
    std::cout << "res = " << res << std::endl;


    return 0;
}