/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 */

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{};
        }

        TreeNode* p_head = root;
        PostOrderTraversalCore(p_head);

        return res_;
    }

   private:
    void PostOrderTraversalIter(TreeNode* p_head) {
        if (p_head == NULL) {
            return;
        }

        std::stack<TreeNode*> tree_node;
        // 用栈暂时存储结果，那么进栈的顺序就是中、右、左，这样出栈的顺序就会是左右中了
        std::stack<int> val_stack;
        tree_node.push(p_head);
        while (!tree_node.empty()) {
            TreeNode* tmp_root = tree_node.top();
            val_stack.push(tmp_root->val);
            tree_node.pop();

            // 注意这两个顺序，右子树先进栈，然后左子树进栈，这样弹出的时候，val_stack的进栈顺序就是中右左了
            if (tmp_root->left) {
                tree_node.push(tmp_root->left);
            }
            if (tmp_root->right) {
                tree_node.push(tmp_root->right);
            }
        }
        while (!val_stack.empty()) {
            res_.push_back(val_stack.top());
            val_stack.pop();
        }
    }

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