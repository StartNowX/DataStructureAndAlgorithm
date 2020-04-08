/**
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。


所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。
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
        RecursiveTree(root, p, q);
        return res;
    }

   private:
    bool RecursiveTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return false;
        }

        // 左子树是否有找到
        int left = RecursiveTree(root->left, p, q) ? 1 : 0;

        // 右子树是否找到
        int right = RecursiveTree(root->right, p, q) ? 1 : 0;

        // 当前节点是否等于q或p中的一个
        int mid = (root == p || root == q) ? 1 : 0;

        // 因为所有节点的值都是唯一的，所以如果当前节点、左子树节点、右子树节点有两个为true，意味着找到了p和q的最近公共祖先
        if (left + mid + right >= 2) {
            res = root;
            return true;
        }
        // 只要有一个找到了，都认为找到了一个
        return (left + mid + right > 0);
    }

   private:
    TreeNode* res = NULL;
};

int main(int argc, char* argv[]) { return 0; }