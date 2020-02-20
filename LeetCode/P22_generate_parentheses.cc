/**
 * Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

#include <iostream>
#include <string>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        if (0 == n) {
            return res_;
        }

        FindNextParenthesis(n, 0, 0, cur_pair);

        return res_;
    }

   private:
    void FindNextParenthesis(int n, int used_left, int used_right,
                             const string& cur_pair) {
        if (used_left == n && used_right == n) {
            // cout << "goes here: " << used_left << ", used_right: " <<
            // used_right
            //      << ", cur_pair: " << cur_pair << endl;
            // cout << endl;
            res_.emplace_back(cur_pair);
            return;
        }

        // 不需要if-else去做选择，只需要对每次加入字符进行限制即可
        // 如果用if-else，会漏掉一些组合
        /*if (used_left == 0) {
            // 左括号未用一次，要用左括号
            FindNextParenthesis(n, used_left + 1, used_right, cur_pair +
            '(');
            // FindNextParenthesis(n, used_left + 1, used_right, cur_pair +
            // ')');

        } else if ((used_left != 0 && used_left == used_right) ||
                   used_left == n) {
            // 左括号和右括号次数一样，已经用完，这两种情况后都需要用右括号
            FindNextParenthesis(n, used_left, used_right + 1, cur_pair +
            ')');
        } */
        if (used_left < n || used_left == 0) {
            // cur_pair += "("; //
            // 这里不能如此，如果这里把cur_pair改变了，则下一步添加右括号时，cur_pair也带有这一步的信息了，区别于P47_permutations2.cc中先emplace_back再pop_back，因为这里cur_pair没有更新
            // cout << "goes left: " << used_left << ", used_right: " <<
            // used_right
            //      << ", cur_pair: " << cur_pair << endl;
            FindNextParenthesis(n, used_left + 1, used_right, cur_pair + "(");
        }

        if (used_right < n && (used_left != 0 && used_left > used_right)) {
            // cout << "goes right: " << used_left
            //      << ", used_right: " << used_right << ", cur_pair: " <<
            //      cur_pair
            //      << endl;
            FindNextParenthesis(n, used_left, used_right + 1, cur_pair + ")");
        }
    }

    string cur_pair;
    vector<string> res_;
};

int main(int argc, char* argv[]) {
    int pair_nums = 3;

    Solution sln;
    auto res = sln.generateParenthesis(pair_nums);

    Utils<string> util;
    util.PrintVector(res);

    return 0;
}