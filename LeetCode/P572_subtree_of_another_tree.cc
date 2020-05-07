/**
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a
subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also
be considered as a subtree of itself.

*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
   public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == NULL && t == NULL) {
            return true;
        }

        return dfs(s, t);
    }

    bool isSubtreeCore(TreeNode *s, TreeNode *t) {
        if (s == NULL && t == NULL) {
            return true;
        }
        if ((s == NULL && t != NULL) || (s != NULL && t == NULL)) {
            return false;
        }

        if (s->val != t->val) {
            return false;
        } else {
            return (isSubtreeCore(s->left, t->left) && isSubtreeCore(s->right, t->right));
        }
    }

    bool dfs(TreeNode *s, TreeNode *t) {
        if (!s) return false;
        // 对于每个节点都要判断当前节点是否满足，以及当前节点的左右节点是否分别满足，比如s为[1,1]和t为[1]，虽然s的根节点没满足，但是其子节点满足了
        return isSubtreeCore(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }
};

int main(int argc, char *argv[]) { return 0; }