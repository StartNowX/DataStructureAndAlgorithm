/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to
display this pattern in a fixed font for better legibility)
 *
        P   A   H   N
        A P L S I I G
        Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 按行读取，主要确定行的方式，即一个变量表示当前行，一个变量表示走的方向
     */
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        // rows表示每行字符数，vector存储所有的行
        vector<string> rows(std::min(numRows, int(s.size())));

        int cur_row = 0;
        bool direction = false;
        for (auto c : s) {
            rows[cur_row] += c;
            if (cur_row == 0 || cur_row == numRows - 1) direction = !direction;

            cur_row += (direction ? 1 : -1);
        }

        string ret;
        for (auto s : rows) ret += s;
        return ret;
    }
};

int main(int argc, char* argv[]) {
    string s = "PAYPALISHIRING";
    Solution sln;
    auto res = sln.convert(s, 4);
    std::cout << "res = " << res << std::endl;

    return 0;
}