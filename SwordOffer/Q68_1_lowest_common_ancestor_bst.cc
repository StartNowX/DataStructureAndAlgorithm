/**
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。

*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // 递归的方式
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 全部再左子树
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {  // 全部再右子树
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }

    TreeNode* lowestCommonAncestorIteration(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* p_head = root;
        while (p_head != NULL) {
            if (p_head->val > p->val && p_head->val > q->val) {
                p_head = p_head->left;
            } else if (p_head->val < p->val && p_head->val < q->val) {
                p_head = p_head->right;
            } else {
                break;
            }
        }

        return p_head;
    }
};

int main(int argc, char* argv[]) { return 0; }