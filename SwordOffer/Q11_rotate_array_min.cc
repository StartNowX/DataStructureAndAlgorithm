/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。 

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 输入是升序序列的一个旋转，则输入的第一个值是第一部分的最小值，因此后面只有有比之小的，都是最小的，直接返回
    // 时间复杂度：O(n)
    int minArray1(vector<int>& numbers) {
        if (0 == numbers.size()) {
            return 0;
        }

        int start_min = numbers[0];
        for (int i = 1; i < numbers.size(); ++i) {
            if (numbers[i] < start_min) {
                return numbers[i];
            }
        }
        return start_min;
    }

    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = numbers.size() - 1;
        // 配合二分查找，O(logn)
        while (left < right) {
            int mid = (left + right) >> 1;
            if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[mid] == numbers[right])
                right--;
            else {
                right = mid;
            }
        }
        return numbers[left];
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{3, 4, 5, 1, 2};
    Solution sln;
    auto res = sln.minArray(nums);
    std::cout << "res = " << res << std::endl;

    return 0;
}