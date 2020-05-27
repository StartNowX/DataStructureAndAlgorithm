/**
 * Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/

/**
 * 和560题思想很像
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 前缀和问题
     * P[i]表示以i为结尾的元素和，sum(i,j) = P[j] - P[i-1], sum(i,j) % K == 0, 即(P[j]-P[i-1]) % K == 0,
     * 也就是P[j] % K == P[i-1] % K
     * 因此，用一个map记录相同的模出现的次数，对于负数的情况要特殊处理
     *
     * 为了考虑前缀和本身能够被K整除，map初始化为{0,1}
     */
    int subarraysDivByK(vector<int>& A, int K) {
        int nums = A.size();
        if (0 == nums) {
            return 0;
        }

        unordered_map<int, int> records{{0, 1}};
        int sum = 0, ans = 0;
        for (auto ele : A) {
            sum += ele;
            // 当sum是负数时，C++取余是负数，需要加上K补回来（比如，K=4，前缀和为-1和3, 3-(-1) = 4, 4能够整除）
            int modules = (sum % K + K) % K;
            if (records.count(modules)) {
                ans += records[modules];
            }
            ++records[modules];
        }

        return ans;
    }

    /**
     * 以[4,5,0,-2,-3,1]，下面的做法在拿到[5]后，没法很好的处理[5,0]，因为他也符合
     */
    int subarraysDivByKWrong(vector<int>& A, int K) {
        int nums = A.size();

        int cnt = 0;
        for (int i = 0; i < nums; ++i) {
            int end = i;
            int sum = A[i];
            while (end <= nums) {
                if (sum % K == 0) {
                    std::cout << "i = " << i << ", sum = " << sum << endl;
                    cnt++;
                    sum = A[i];
                    end++;
                } else {
                    if (end == nums) {
                        break;
                    }
                    sum += A[end++];
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) { return 0; }