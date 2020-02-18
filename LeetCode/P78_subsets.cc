/**
 * Given a set of distinct integers, nums, return all possible subsets (the
power set).
Note: The solution set must not contain duplicate subsets.

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>

#include "utils/include/utils.h"

using namespace std;

// 回溯法,backtracking
void GetSubRes(vector<vector<int>>& res, const vector<int>& num,
               int start_index, vector<int>& tmp_vec) {
    res.emplace_back(tmp_vec);

    for (int i = start_index; i < num.size(); ++i) {
        tmp_vec.emplace_back(num[i]);
        GetSubRes(res, num, i + 1, tmp_vec);
        tmp_vec.pop_back();
    }
}

vector<vector<int>> Subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    GetSubRes(res, nums, 0, tmp);

    return res;
}

int main(int argc, char* argv[]) {
    // {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<int> all_nums{1, 2, 3};

    Utils<int> util;

    auto res = Subsets(all_nums);

    util.PrintVector2D(res);

    return 0;
}