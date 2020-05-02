/**
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

// 树形结构的动态规划

#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    // 递归动态规划，容易超时
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int money = root->val;
        if (root->left) {
            money += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right) {
            money += (rob(root->right->left) + rob(root->right->right));
        }

        return std::max(money, rob(root->left) + rob(root->right));
    }

    // 还可以继续优化，这种记忆化的方式，没有把所有的重复子问题全部解决掉，见下一个
    int robWithMem(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int money = root->val;
        if (root->left) {
            int val;
            if (mem_.find(root->left->left) == mem_.end()) {
                val = robWithMem(root->left->left);
                mem_[root->left->left] = val;
                money += val;
            } else {
                money += mem_[root->left->left];
            }

            if (mem_.find(root->left->right) == mem_.end()) {
                val = robWithMem(root->left->right);
                mem_[root->left->right] = val;
                money += val;
            } else {
                money += mem_[root->left->right];
            }
        }

        if (root->right) {
            int val;
            if (mem_.find(root->right->left) == mem_.end()) {
                val = robWithMem(root->right->left);
                mem_[root->right->left] = val;
                money += val;
            } else {
                money += mem_[root->right->left];
            }

            if (mem_.find(root->right->right) == mem_.end()) {
                val = robWithMem(root->right->right);
                mem_[root->right->right] = val;
                money += val;
            } else {
                money += mem_[root->right->right];
            }
        }

        return std::max(money, robWithMem(root->left) + robWithMem(root->right));
    }

    int robWithMemBetter(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (mem_.find(root) != mem_.end()) return mem_[root];

        int money = root->val;
        if (root->left) {
            money += (robWithMemBetter(root->left->left) + robWithMemBetter(root->left->right));
        }
        if (root->right) {
            money += (robWithMemBetter(root->right->left) + robWithMemBetter(root->right->right));
        }

        int res = std::max(money, robWithMemBetter(root->left) + robWithMemBetter(root->right));
        mem_[root] = res;
        return res;
    }

    int robExtreme(TreeNode* root) {
        // 用2维数组表示当前节点偷或不偷，0为不偷，1为偷
        std::vector<int> rob_or_not(2, 0);
        rob_or_not = robExtremeCore(root);
        return std::max(rob_or_not[0], rob_or_not[1]);
    }

    vector<int> robExtremeCore(TreeNode* root) {
        if (root == NULL) return vector<int>(2, 0);

        vector<int> res(2, 0);
        vector<int> left, right;
        left = robExtremeCore(root->left);
        right = robExtremeCore(root->right);

        res[0] = std::max(left[0], left[1]) + std::max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
    }
private:
    std::unordered_map<TreeNode*, int> mem_;
};


int main(int argc, char* argv[]) {
    return 0;
}