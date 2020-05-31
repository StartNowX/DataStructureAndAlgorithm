/**
 * Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
*/


#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    /**
     * 迭代
     */
    bool isSameTreeIter(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();

            if (!p && !q) continue;
            if ((!p || !q) || (p->val != q->val)) {
                return false;
            }

            que.push(p->left);
            que.push(q->left);

            que.push(p->right);
            que.push(q->right);
        }
        return true;
    }
};