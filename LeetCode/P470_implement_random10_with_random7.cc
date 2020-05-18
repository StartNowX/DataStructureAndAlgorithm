/**
 * Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which
generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

    Input: 1
    Output: [7]

    Input: 2
    Output: [8,4]

    Input: 3
    Output: [8,1,10]
*/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <stdlib.h>

#include <iostream>

class Solution {
   public:
    int rand10() {
        // 两次rand7()产生数的范围是1-49，舍弃41-49，用1-40拟合1-10
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);

        return 1 + (idx - 1) % 10;
    }

   private:
    inline int rand7() { return std::rand() % 7 + 1; }
};

int main(int argc, char* argv[]) { return 0; }