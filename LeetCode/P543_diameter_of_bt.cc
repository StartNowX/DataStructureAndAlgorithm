/**
* Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
    * 递归的方式：找出以某个点为根节点遍历所走过的最长的节点数，总路径则为最长的节点数减去1
    * 
    */
    int diameterOfBinaryTree(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }

        (void)depth(root);
        return diameter_ - 1;
    }
private:
    int depth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }

        int L = depth(root->left);
        int R = depth(root->right);
        diameter_ = std::max(diameter_, L+R+1);

        return std::max(L, R) + 1;
    }

    int diameter_ = 0;
};

int main(int argc, char* argv[]) {return 0;}