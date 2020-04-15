/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{};
        }

        TreeNode* p_head = root;
        PostOrderTraversalCore(p_head);

        return res_;
    }

   private:
    void PostOrderTraversalCore(TreeNode* p_head) {
        if (p_head == NULL) {
            return;
        }

        if (p_head->left != NULL) {
            PostOrderTraversalCore(p_head->left);
        }

        if (p_head->right != NULL) {
            PostOrderTraversalCore(p_head->right);
        }

        res_.emplace_back(p_head->val);

        return;
    }

   private:
    vector<int> res_;
};

int main(int argc, char* argv[]) { return 0; }