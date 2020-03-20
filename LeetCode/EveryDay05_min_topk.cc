/**
 * 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 *
 * 输入：arr = [3,2,1], k = 2
    输出：[1,2] 或者 [2,1]

    输入：arr = [0,1,2,1], k = 1
    输出：[0]
 */


#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

#include "utils/include/time_log.h"
#include "utils/include/utils.h"

using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (0 == arr.size()) {
            return res;
        }

        if (k == arr.size()) {
            return arr;
        }

        sort(arr.begin(), arr.end());
        for (size_t i = 0; i < arr.size(); ++i) {
            if (i < k) {
                res.emplace_back(arr[i]);
            } else {
                break;
            }
        }

        return res;
    }

    // 大顶堆
    vector<int> getLeastNumbersWithGreatHeap(vector<int>& arr, int k) {
        vector<int> res;
        if (0 == arr.size() || k == 0) {
            return res;
        }

        if (k == arr.size()) {
            return arr;
        }

        std::priority_queue<int> Q;
        // 始终维护大小为k的大顶堆
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        // 当剩余的元素比大顶堆堆顶小，则把堆顶pop，加入新数据
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < Q.top()) {
                Q.pop();
                Q.push(arr[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            res.emplace_back(Q.top());
            Q.pop();
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> vec{3, 2, 1};
    int topk = 2;

    Utils<int> util_int;
    Solution sln;
    {
        TimeLog log("getLeastNumbers");
        auto res = sln.getLeastNumbersWithGreatHeap(vec, topk);
        util_int.PrintVector(res);
    }

    return 0;
}
