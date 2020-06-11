/**
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you
would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1,
1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30,
100].
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 构造一个单调栈，从栈底到栈顶对应元素代表的温度依次递减。当栈为空或栈顶元素代表的温度比当前元素的温度高时，当前元素对应的index入栈
     *
     * 每次弹出栈顶元素时，更新栈顶元素（index）对应的ans数组
     *
     * 时间复杂度O(n)，空间复杂度O(n)
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        int length = T.size();
        if (0 == length) {
            return vector<int>{};
        }

        vector<int> ans(length, 0);
        stack<int> st;
        for (int i = 0; i < length; ++i) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int prev_index = st.top();
                ans[prev_index] = i - prev_index;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }

    /**
     * 两次循环的做法，超时
     *
     * 内部循环查找用二分法不行，元素有重复的，不能保证找到的是最左边的
     */
    vector<int> dailyTemperaturesTimeOut(vector<int>& T) {
        int length = T.size();
        if (0 == length) {
            return vector<int>{};
        }

        vector<int> ans;
        for (int i = 0; i < length; ++i) {
            int wait_day = -1;
            for (int j = i; j < length; ++j) {
                if (T[j] > T[i]) {
                    wait_day = j - i;
                    ans.push_back(wait_day);
                    break;
                }
            }
            if (wait_day == -1) {
                ans.push_back(0);
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) { return 0; }