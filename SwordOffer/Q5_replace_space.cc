/**
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 *
 * 输入：s = "We are happy."
 * 输出："We%20are%20happy."
 */

#include <iostream>
#include <string>


using namespace std;

class Solution {
   public:
    string replaceSpace(string s) {
        int cnt = CountSpace(s);

        int new_len = s.length() + 2 * cnt;
        int new_index = new_len - 1;
        int old_index = s.length() - 1;

        std::string res(new_len, '0');

        while (old_index >= 0 && new_index >= 0) {
            if (isspace(s[old_index])) {
                res[new_index--] = '0';
                res[new_index--] = '2';
                res[new_index--] = '%';

                --old_index;
            } else {
                res[new_index--] = s[old_index--];
            }
        }

        return res;
    }

   private:
    int CountSpace(const std::string& str) {
        int cnt = 0;
        for (auto& s : str) {
            if (isspace(s)) {
                cnt++;
            }
        }
        return cnt;
    }
};


int main(int argc, char* argv[]) {
    std::string str = "We are happy";

    Solution sln;
    auto res = sln.replaceSpace(str);
    std::cout << "res = " << res << std::endl;


    return 0;
}