/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{};
        }

        TreeNode* p_head = root;
        // PreOrderTraversalCore(p_head);
        PreorderTraversalIter(p_head);

        return res_;
    }

   private:
    void MariosTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        TreeNode* p_head = root;
        TreeNode* pre_node;
        while (p_head) {
            if (p_head->left == NULL) {
                res_.emplace_back(p_head->val);
                p_head = p_head->right;
            } else {
                pre_node = p_head->left;
                // 一定要有第二个判断
                while (pre_node->right && pre_node->right != p_head) {
                    pre_node = pre_node->right;
                }

                if (pre_node->right == NULL) {
                    // 注意这里是将p_head（而不是p_head）赋给pre_node->right
                    pre_node->right = p_head;
                    res_.emplace_back(p_head->val);
                    p_head = p_head->left;
                }

                // 打破循环，例如对[1,2,3,4,5,6]，最后3的左子树为6，6的右子树为3，进入死循环了
                if (pre_node->right == p_head) {
                    pre_node->right = NULL;
                    p_head = p_head->right;
                }
            }
        }
    }

    void PreorderTraversalIter(TreeNode* p_head) {
        std::stack<TreeNode*> tree_stack;
        tree_stack.push(p_head);
        while (!tree_stack.empty()) {
            TreeNode* tmp_root = tree_stack.top();
            res_.emplace_back(tmp_root->val);
            tree_stack.pop();
            // 先进后出，右子树先进栈，注意和后序遍历区分开
            if (tmp_root->right != NULL) {
                tree_stack.push(tmp_root->right);
            }
            if (tmp_root->left != NULL) {
                tree_stack.push(tmp_root->left);
            }
        }
        return;
    }

    void PreOrderTraversalCore(TreeNode* p_head) {
        if (p_head == NULL) {
            return;
        }

        res_.emplace_back(p_head->val);
        if (p_head->left != NULL) {
            PreOrderTraversalCore(p_head->left);
        }
        if (p_head->right != NULL) {
            PreOrderTraversalCore(p_head->right);
        }
        return;
    }

   private:
    vector<int> res_;
};

int main(int argc, char* argv[]) { return 0; }