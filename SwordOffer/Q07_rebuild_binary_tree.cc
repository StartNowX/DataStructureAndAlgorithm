/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        preorder_ = preorder;
        inorder_ = inorder;

        // 建立前序遍历中元素和中序遍历中对应元素index的对应map，方便递归时查找
        for (auto& n : preorder) {
            for (int i = 0; i < inorder.size(); ++i) {
                if (inorder[i] == n) {
                    pre_in_map_[n] = i;
                }
            }
        }

        int pre_len = preorder.size();
        int in_len = inorder.size();
        return BuildTreeCore(0, pre_len - 1, 0, in_len - 1);
    }

   private:
    TreeNode* BuildTreeCore(int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right || in_left > in_right) {
            return NULL;
        }

        int root = preorder_[pre_left];
        TreeNode* node = new TreeNode(root);

        int in_index = pre_in_map_[root];

        // 这里是pre_left+(in_index-in_left)
        node->left = BuildTreeCore(pre_left + 1, pre_left + (in_index - in_left), in_left, in_index - 1);
        // 这里是pre_left + (in_index - in_left) + 1，in_index -
        // in_left可以认为才是pre_left真正该移动的步长，再加上1，向后又走一位
        node->right = BuildTreeCore(pre_left + (in_index - in_left) + 1, pre_right, in_index + 1, in_right);
        return node;
    }

   private:
    vector<int> preorder_;
    vector<int> inorder_;
    std::unordered_map<int, int> pre_in_map_;
};


int main(int argc, char* argv[]) {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    Solution sln;
    auto res = sln.buildTree(preorder, inorder);


    return 0;
}
