/**
 * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

*/

#include <iostream>

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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return FindDepthDfs(root);
    }

   private:
    int FindDepthDfs(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }

        int left_height = FindDepthDfs(root->left);
        int right_height = FindDepthDfs(root->right);

        /**
         * 对于左右子树有一个为空的情况，需要特殊处理，如果也是去min的话，最小值就是0了
         *
         * 因此，左子树为空的话，该节点的深度就是右子树深度+1，右子树为空的话，该节点的深度就是左子树深度+1
         */
        if (root->left && root->right) {
            return 1 + std::min(left_height, right_height);
        } else if (!root->left) {
            return 1 + right_height;
        } else {
            return 1 + left_height;
        }
    }
};