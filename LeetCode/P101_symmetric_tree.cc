/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return CheckbinaryRecursively(root, root);
    }

   private:
    /**
     * 递归的方式
     */
    bool CheckbinaryRecursively(TreeNode* p1, TreeNode* p2) {
        if (!p1 && !p2) {
            return true;
        }

        if (!p1 || !p2) {
            return false;
        }

        return p1->val == p2->val && CheckbinaryRecursively(p1->left, p2->right) &&
               CheckbinaryRecursively(p1->right, p2->left);
    }

    /**
     * 迭代的方式，用队列
     */
    bool CheckbinaryIteration(TreeNode* u, TreeNode* v) {
        std::queue<TreeNode*> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v) continue;
            if (!u || !v || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }
};