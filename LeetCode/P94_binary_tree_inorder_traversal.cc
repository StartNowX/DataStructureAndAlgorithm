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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{};
        }

        TreeNode* p_head = root;
        InOrderTraversalCore(p_head);

        return res_;
    }

   private:
    // 利用线索二叉树
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
                while (pre_node->right) {
                    pre_node = pre_node->right;
                }
                // 根节点的左子树的最右子树的右节点的后续节点是根节点
                pre_node->right = p_head;
                TreeNode* tmp = p_head;
                p_head = p_head->left;  // 继续找左子树
                tmp->left = NULL;       //原根节点要置为NULL，防止死循环
            }
        }
    }

    void InOrderTraversalIter(TreeNode* p_head) {
        if (p_head == NULL) {
            return;
        }

        std::stack<TreeNode*> tree_stack;  // 不再先把根节点进栈了

        while (p_head || !tree_stack.empty()) {
            // 一直迭代将树的左子树进栈
            while (p_head) {
                tree_stack.push(p_head);
                p_head = p_head->left;
            }

            // 这时应该是最左的节点了，取出值
            p_head = tree_stack.top();
            res_.emplace_back(p_head->val);
            tree_stack.pop();
            // 左节点和中间节点已经遍历完，这里只需要遍历右子树了
            p_head = p_head->right;
        }

        return;
    }

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