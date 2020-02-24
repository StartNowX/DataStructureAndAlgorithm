/**
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where
 * "adjacent" cells are those horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 * board =
    [
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
    ]

    Given word = "ABCCED", return true.
    Given word = "SEE", return true.
    Given word = "ABCB", return false.

 */

#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    template <typename T>
    using dime2d_type = vector<vector<T>>;

    bool exist(dime2d_type<char>& board, string word) {
        // 这里对棋盘进行遍历，而没有先去找出第一个点出现的所有位置，
        // 如果当前点找到了word的index个字母，就找word的index+1的字母，如果没找到，就到棋盘下个点找
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (FindLetterInBoard(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

   private:
    void FindNextElement(const dime2d_type<char>& board, string word, int index) {
        if (index == word.size()) {
            // cout << "true, " << index << endl;
            is_word_exists_ = true;
            return;
        }

        // 处理“ABCB”还会有问题，B被重复利用了
        for (auto ele_index : last_ele_indexes_) {
            if (IsAdjacentExists(board, ele_index, word[index])) {
                last_ele_indexes_ = FindElementIndex(board, word[index]);
                FindNextElement(board, word, index + 1);
                is_word_exists_ = true;
                return;
            }
        }

        is_word_exists_ = false;
        return;
    }

    dime2d_type<int> FindElementIndex(const dime2d_type<char>& board, char first_ele) {
        vector<vector<int>> ele_indexes;
        int i = 0;
        int j = 0;
        for (auto x_board : board) {
            for (auto y_board : x_board) {
                if (first_ele == y_board) {
                    ele_indexes.emplace_back(vector<int>{i, j});
                }
                j++;
            }
            i++;
            j = 0;
        }
        return ele_indexes;
    }

    bool IsAdjacentExists(const dime2d_type<char>& board, const vector<int>& candidates, char target) {
        int x = candidates[0];
        int y = candidates[1];
        // cout << "char: " << target << endl;
        // cout << "x = " << x << ", y = " << y << endl;

        auto tmp_indexes = FindElementIndex(board, target);
        for (auto index : tmp_indexes) {
            // cout << "target = " << target << ", x = " << x << ", y = " << y
            //      << ", index_x = " << index[0] << ", index[1] = " << index[1]
            //      << endl;
            if (x == index[0]) {
                return std::abs(y - index[1]) == 1;
            }

            if (y == index[1]) {
                return std::abs(x - index[0]) == 1;
            }
        }

        return false;
    }

    bool FindLetterInBoard(dime2d_type<char>& board, const string& word, int index, int board_x, int board_y) {
        if (word[index] != board[board_x][board_y]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        char tmp = board[board_x][board_y];
        // 暂时置0, 相当于标记该位置已经被使用过了(因为全是字符串)
        board[board_x][board_y] = 0;
        // 这个搜索的方式有意思，只需要以当前点的左边和边界情况进行对比就行了
        // 不需要取考虑当前点是否在第一行第一列或者第一行最后一列的情况
        if (board_x > 0 && FindLetterInBoard(board, word, index + 1, board_x - 1, board_y) ||                 // 向左
            board_y > 0 && FindLetterInBoard(board, word, index + 1, board_x, board_y - 1) ||                 // 向上
            board_x < board.size() - 1 && FindLetterInBoard(board, word, index + 1, board_x + 1, board_y) ||  // 向右
            board_y < board[board_x].size() - 1 &&
                FindLetterInBoard(board, word, index + 1, board_x, board_y + 1)) {  // 向下
            return true;
        }
        // 如果没有找到，则将该位置重新标记为未使用
        board[board_x][board_y] = tmp;
        return false;
    }

   private:
    dime2d_type<int> last_ele_indexes_;
    dime2d_type<int> neighbours{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    dime2d_type<int> visited;
    bool is_word_exists_;
};

int main(int argc, char* argv[]) {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";  //"SEE";  //"ABCCED"; // 暴力搜索

    Solution sln;
    auto res = sln.exist(board, word);
    cout << "res = " << res << endl;
    return 0;
}