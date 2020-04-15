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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{};
        }

        TreeNode* p_head = root;
        InOrderTraversalCore(p_head);

        return res_;
    }

   private:
    void InOrderTraversalCore(TreeNode* p_head) {
        if (p_head == NULL) {
            return;
        }

        if (p_head->left != NULL) {
            InOrderTraversalCore(p_head->left);
        }
        res_.emplace_back(p_head->val);
        if (p_head->right != NULL) {
            InOrderTraversalCore(p_head->right);
        }
        return;
    }

   private:
    vector<int> res_;
};

int main(int argc, char* argv[]) { return 0; }