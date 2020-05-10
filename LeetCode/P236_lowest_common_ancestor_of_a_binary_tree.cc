/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

同：SwordOffer的Q68_2_lowest_common_ancestor_binar_tree.cc
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL) {
            return NULL;
        }
        LCA(root, p, q);
        return res_;
    }

   private:
    bool LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return false;
        }

        int left = LCA(root->left, p, q) ? 1 : 0;
        int right = LCA(root->right, p, q) ? 1 : 0;
        int mid = (root == p || root == q) ? 1 : 0;

        if (left + right + mid >= 2) {
            res_ = root;
            return true;
        }

        return left + right + mid >= 1;
    }

   private:
    TreeNode* res_;
};

int main(int argc, char* argv[]) { return 0; }