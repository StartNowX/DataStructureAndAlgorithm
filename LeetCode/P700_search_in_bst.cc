/**
 * Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's
value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return
NULL.

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2

      2
     / \
    1   3
*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* p_head = root;
        while (p_head != NULL) {
            if (p_head->val > val) {
                p_head = p_head->left;
            } else if (p_head->val < val) {
                p_head = p_head->right;
            } else {
                return p_head;
            }
        }

        return NULL;
    }
};

int main(int argc, char argv[]) { return 0; }