/**
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

*/

#include <iostream>
#include <vector>

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
    bool IsBalancedFromBottomToUp(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int height = 0;
        return IsBalancedFromBottomToUp(root, height);
    }

    /**
     * 递归的判断根节点及左右子节点是否为平衡二叉树
     * 自顶向下的方式，存在height的重复计算
     */
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return (std::abs(GetTreeHeight(root->left) - GetTreeHeight(root->right)) <= 1) && isBalanced(root->left) &&
               isBalanced(root->right);
    }

   private:
    int GetTreeHeight(TreeNode* root) {
        // empty tree has height -1, as it's calculated recursively
        if (root == NULL) {
            return -1;
        }
        return 1 + max(GetTreeHeight(root->left), GetTreeHeight(root->right));
    }

    // 自底向上
    bool IsBalancedFromBottomToUp(TreeNode* root, int& height) {
        if (root == NULL) {
            height = -1;
            return true;
        }

        int left_h, right_h;
        if (IsBalancedFromBottomToUp(root->left, left_h) && IsBalancedFromBottomToUp(root->right, right_h) &&
            std::abs(left_h - right_h) < 2) {
            height = std::max(left_h, right_h) + 1;
            return true;
        }

        return false;
    }
};