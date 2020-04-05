/**
 * 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)，B是A的子结构，
即A中有出现和B相同的结构和节点值。
 * 给定的树 A:

     3
    / \
   4   5
  / \
 1   2

给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        bool flag = false;

        // 将边缘条件的判断下放到DoesSubTreeSame中去做，作为递归的终止条件
        if (A != NULL && B != NULL) {
            // 根节点一致，则匹配各自的子树
            if (A->val == B->val) {
                flag = DoesSubTreeSame(A, B);
            }
            if (!flag) {
                flag = isSubStructure(A->left, B);
            }
            if (!flag) {
                flag = isSubStructure(A->right, B);
            }
        }
        return flag;
    }

   private:
    bool DoesSubTreeSame(TreeNode *A, TreeNode *B) {
        // 子结构已经匹配到叶子结点了
        if (B == NULL) {
            return true;
        }

        // B不为null，而A却已经为null了，说明完全匹配到
        if (A == NULL) {
            return false;
        }

        if (A->val != B->val) {
            return false;
        }

        return DoesSubTreeSame(A->left, B->left) && DoesSubTreeSame(A->right, B->right);
    }
};

int main(int argc, char *argv[]) { return 0; }