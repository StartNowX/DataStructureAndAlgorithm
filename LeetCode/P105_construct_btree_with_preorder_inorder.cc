/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * You may assume that duplicates do not exist in the tree.
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]

    3
   / \
  9  20
    /  \
   15   7

同剑指offer中的第七题，Q07_rebuild_binary_tree.cc
*/


#include <iostream>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) {
            return NULL;
        }

        GetPreOrderInOrderMap(preorder, inorder);

        TreeNode* p_head = NULL;

        p_head = BuildTreeCore(preorder, inorder, 0, pre_len_ - 1, 0, in_len_ - 1);

        return p_head;
    }

   private:
    /**
     * pre_l和pre_r, 代表前序遍历对应的左边起始部分和右边终止部分
     * in_l和in_r，代表中序遍历对应的左边起始部分和右边终止部分
     */
    TreeNode* BuildTreeCore(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l > pre_r || in_l > in_r) {
            return NULL;
        }
        int root_ele = preorder[pre_l];
        int inorder_index = pre_in_map_[root_ele];

        TreeNode* tmp = new TreeNode(root_ele);
        tmp->left =
            BuildTreeCore(preorder, inorder, pre_l + 1, pre_l + (inorder_index - in_l), in_l, inorder_index - 1);
        // 要注意左边的起始点是要+1的
        tmp->right =
            BuildTreeCore(preorder, inorder, pre_l + (inorder_index - in_l) + 1, pre_r, inorder_index + 1, in_r);

        return tmp;
    }

    void GetPreOrderInOrderMap(vector<int>& preorder, vector<int>& inorder) {
        pre_len_ = preorder.size();
        in_len_ = inorder.size();
        for (auto pre_ele : preorder) {
            for (int i = 0; i < inorder.size(); ++i) {
                if (pre_ele == inorder[i]) {
                    pre_in_map_[pre_ele] = i;
                }
            }
        }

        return;
    }
    // preorder中元素在inorder中的index
    std::unordered_map<int, int> pre_in_map_;
    int pre_len_;
    int in_len_;
};