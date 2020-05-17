/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as
a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to
finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses,
return an empty array.

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
             course 0. So the correct course order is [0,1] .

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges_.resize(numCourses);
        visited_.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges_[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && !invalid_; ++i) {
            if (!visited_[i]) {
                dfs(i);
            }
        }

        if (invalid_) {
            return {};
        }

        // 下标0是栈底，因此需要翻转
        reverse(result_.begin(), result_.end());

        return result_;
    }

   private:
    void dfs(int u) {
        visited_[u] = 1;  //

        for (auto v : edges_[u]) {
            if (visited_[v] == 0) {
                dfs(v);
                if (invalid_) {
                    return;
                }
            } else if (visited_[v] == 1) {
                invalid_ = true;
                return;
            }
        }

        visited_[u] = 2;
        result_.push_back(u);
    }

    vector<vector<int>> edges_;
    vector<int> visited_;  // 0-unsearch, 1-searching, 2-finished
    vector<int> result_;
    bool invalid_;
};

int main(int argc, char* argv[]) { return 0; }