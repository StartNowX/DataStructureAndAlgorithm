/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/

#include <climits>
#include <iostream>
#include <stack>
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
    // 中序遍历
    bool isValidBSTInOrder(TreeNode* root) {
        std::stack<TreeNode*> node_stack;
        long long inorder = LONG_MIN;
        while (!node_stack.empty() || root != NULL) {
            while (root != NULL) {
                node_stack.push(root);
                root = root->left;
            }

            root = node_stack.top();
            node_stack.pop();
            if (inorder >= root->val) return false;

            inorder = root->val;
            root = root->right;
        }

        return true;
    }


    // 遍历的方法
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        CheckSubNode(root, LONG_MIN, LONG_MAX);

        return is_bst_;
    }

    void CheckSubNode(TreeNode* root, long long lower, long long higher) {
        if (root == NULL) {
            return;
        }

        // 对当前节点不区分看是否处于上下限中，同时注意是>=
        if (root->val <= lower || root->val >= higher) {
            is_bst_ = false;
            return;
        }

        CheckSubNode(root->left, lower, root->val);
        CheckSubNode(root->right, root->val, higher);
        return;
    }

   private:
    bool is_bst_ = true;
};

int main(int argc, char* argv[]) { return 0; }