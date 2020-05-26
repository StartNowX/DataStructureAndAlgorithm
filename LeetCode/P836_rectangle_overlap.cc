/**
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner,
and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at
the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Both rectangles rec1 and rec2 are lists of 4 integers.
All coordinates in rectangles will be between -10^9 and 10^9.

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 直接检查区域就行了，如果用IoU的计算方式的话，需要考虑一些边界情况
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1.size() == 0 || rec2.size() == 0) {
            return false;
        }

        return std::min(rec1[2], rec2[2]) > std::max(rec1[0], rec1[0]) &&
               std::min(rec1[3], rec2[3]) > std::max(rec1[1], rec2[1]);
    }
};

int main(int argc, char* argv[]) { return 0； }