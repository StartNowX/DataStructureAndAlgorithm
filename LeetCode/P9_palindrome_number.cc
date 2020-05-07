/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Input: 121
Output: true


Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Coud you solve it without converting the integer to a string?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<int> bits;
        while (x) {
            int tmp = x % 10;
            x /= 10;
            bits.emplace_back(tmp);
        }

        int end = bits.size() - 1;
        int start = 0;
        while (start < end) {
            if (bits[end] == bits[start]) {
                end--;
                start++;
            } else {
                return false;
            }
        }

        return true;
    }

    bool isPalindromMoreEfficient(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // 将x翻转（只需要翻转长度的一半，即x>rev_num）
        int rev_num = 0;
        while (x > rev_num) {
            rev_num = rev_num * 10 + x % 10;
            x /= 10;
        }

        // 对于X长度为奇数的情况，将翻转后的rev_num整除10，因为经过上面的while循环，rev_num的最后一位应该是X的中间位
        return x == rev_num || x == (rev_num / 10);
    }
};

int main(int argc, char* argv[]) {
    Solution sln;
    auto res = sln.isPalindromMoreEfficient(505);
    std::cout << "res = " << res << std::endl;

    return 0;
}
