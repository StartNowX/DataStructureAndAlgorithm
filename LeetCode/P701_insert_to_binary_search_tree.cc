/**
 * Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the
BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the
original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You
can return any of them.

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5

         4
       /   \
      2     7
     / \   /
    1   3 5

             5
       /   \
      2     7
     / \
    1   3
         \
          4
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (NULL == root) {
            return NULL;
        }

        TreeNode* p_head = root;
        InsertSubBst(p_head, val);
        return p_head;
    }

   private:
    // 递归的方法，还可以用迭代的方法
    void InsertSubBst(TreeNode* root, int val) {
        TreeNode* tmp = new TreeNode(val);
        // 由于二叉搜索树的特性，插入的节点肯定是叶子结点为空的点
        if (root->left == NULL && root->val > val) {
            root->left = tmp;
            return;
        }
        if (root->right == NULL && root->val < val) {
            root->right = tmp;
            return;
        }

        if (root->val > val) {
            InsertSubBst(root->left, val);
        } else {
            InsertSubBst(root->right, val);
        }
        return;
    }
};

int main(int argc, char* argv[]) { return 0; }