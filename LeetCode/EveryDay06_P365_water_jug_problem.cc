/**
 * You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You
need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

    Input: x = 3, y = 5, z = 4
    Output: True

    Input: x = 2, y = 6, z = 5
    Output: False
*/

#include <math.h>

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

using PII = pair<int, int>;

class Solution {
   public:
    // 数学推理，贝祖定理
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || z == x + y;
        return z % gcd(x, y) == 0;
    }

    // bfs
    // https://leetcode-cn.com/problems/water-and-jug-problem/solution/tu-jie-bfs-c-jie-zhu-unordered_set-queue-shi-xian-/
    bool canMeasureWaterBFS(int x, int y, int z) {
        std::unordered_set<PII, HashPair> mark;

        std::queue<PII> q;
        q.push(make_pair(0, 0));  // 初始化

        while (q.empty() == false) {
            auto f = q.front();
            q.pop();

            // 找到最终状态
            if (f.first + f.second == z) {
                return true;
            }
            //遍历当前点的所有操作，广度
            for (int i = 0; i < kOpNum; ++i) {
                auto next = op(i, f, x, y);
                // 找到该点，说明已经执行过，不再执行
                if (mark.find(next) != mark.end()) {
                    continue;
                }

                mark.insert(next);
                q.push(next);
            }
        }

        return false;
    }

   private:
    // 求最大公约数
    int gcd(int x, int y) {
        int tmp;
        if (0 == x || 0 == y) {
            return 0;
        }

        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        while (y != 0) {
            tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }

    // 定义不同的操作
    // 对应的几种操作，主要有倒满A/B，倒空A/B，A倒入B，B倒入A
    std::pair<int, int> op(int type, const PII& state, int x, int y) {
        switch (type) {
            case 0:
                return make_pair(x, state.second);  // 倒满A
            case 1:
                return make_pair(state.first, y);  // 倒满B
            case 2:
                return make_pair(0, state.second);  // 倒空B
            case 3:
                return make_pair(state.first, 0);  // 倒空A
            case 4: {
                int move = std::min(state.first, y - state.second);
                return make_pair(state.first - move, state.second + move);  // A倒入B
            }
            case 5: {
                int move = std::min(x - state.first, state.second);
                return make_pair(state.first + move, state.second - move);  // B倒入A
            }
        }
        return make_pair(0, 0);  // 回到初始状态
    }

   private:
    struct HashPair {
        size_t operator()(const PII& key) const noexcept {
            // 保证每个数唯一
            return (size_t)(key.first) * 100000007 + key.second;
        }
    };

    constexpr static int kOpNum = 6;
};

int main(int argc, char* argv[]) {
    int x = 3;
    int y = 5;
    int z = 4;

    Solution sln;
    // auto res = sln.canMeasureWater(x, y, z);
    auto res = sln.canMeasureWaterBFS(x, y, z);
    std::cout << "res = " << res << std::endl;

    return 0;
}