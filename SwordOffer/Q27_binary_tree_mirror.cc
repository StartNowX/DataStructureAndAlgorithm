/**
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 *      4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (NULL == root) {
            return NULL;
        }

        TreeNode *mirror_node = NULL;
        mirror_node = find_sub_node(root);
        return mirror_node;
    }

   private:
    TreeNode *find_sub_node(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode *tmp_node = new TreeNode(root->val);
        if (root->right != NULL) {
            tmp_node->left = find_sub_node(root->right);
        }
        if (root->left != NULL) {
            tmp_node->right = find_sub_node(root->left);
        }

        return tmp_node;
    }
};


int main(int argc, char *argv[]) { return 0; }