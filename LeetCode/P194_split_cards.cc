/**
 *In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups
of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.

    Input: deck = [1,2,3,4,4,3,2,1]
    Output: true
    Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

    Input: deck = [1,1,2,2,2,2]
    Output: true
    Explanation: Possible partition [1,1],[2,2],[2,2].


 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    // method: 暴力，找到所有元素的个数，然后么个元素的个数，如果所有元素的个数都是2的倍数，则OK
    // method: 如果存在的话，则X肯定是所有元素的所有card的个数的最大公约数
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = static_cast<int>(deck.size());
        // vector<int> cnt{len, 0};
        unordered_map<int, int> cnt;

        if (len <= 1) {
            return false;
        }

        for (auto n : deck) {
            cnt[n]++;
        }

        int g = 0;

        for (auto c : cnt) {
            if (c.second) {
                g = gcd(g, c.second);
            }
        }

        return g >= 2 ? true : false;
    }

   private:
    int gcd(int x, int y) { return !x ? y : gcd(y % x, x); }
    // vector<int> cnt(1000, 0); // error, 还没有对象就指定了cnt的大小
};

int main(int argc, char* argv[]) {
    vector<int> vec{1, 2, 3, 4, 4, 3, 2, 1};

    Solution sln;
    auto res = sln.hasGroupsSizeX(vec);
    std::cout << "res = " << res << std::endl;

    return 0;
}