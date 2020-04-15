/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0 || (postorder.size() != inorder.size())) {
            return NULL;
        }

        GetInorderPostorderMap(inorder, postorder);

        TreeNode* root;
        root = BuildTreeCore(inorder, postorder, 0, in_len_ - 1, 0, post_len_ - 1);
        return root;
    }

   private:
    TreeNode* BuildTreeCore(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_start,
                            int post_end) {
        if (in_start > in_end || post_start > post_end) {
            return NULL;
        }

        int root_val = postorder[post_end];
        int in_index = in_post_index_map_[root_val];

        TreeNode* cur_node = new TreeNode(root_val);
        // cur_node->left = BuildTreeCore(inorder, postorder, in_start, in_index - 1, post_start, post_end - 1);
        // cur_node->right = BuildTreeCore(inorder, postorder, in_index + 1, in_end, in_index, post_end - 1);

        // 和P105一样，每次先找到根结点，然后找到根结点在中序遍历中的位置
        // 这里关键是下次更新后序遍历的起始点的计算方式，post_start + (in_index - in_instart)
        cur_node->left = BuildTreeCore(inorder, postorder, in_start, in_index - 1, post_start,
                                       post_start + (in_index - in_start) - 1);
        cur_node->right =
            BuildTreeCore(inorder, postorder, in_index + 1, in_end, post_start + (in_index - in_start), post_end - 1);
        return cur_node;
    }

    void GetInorderPostorderMap(vector<int>& inorder, vector<int>& postorder) {
        in_len_ = static_cast<int>(inorder.size());
        post_len_ = static_cast<int>(postorder.size());
        for (auto s : postorder) {
            for (int i = 0; i < in_len_; ++i) {
                if (inorder[i] == s) {
                    in_post_index_map_[s] = i;
                }
            }
        }
    }

    std::unordered_map<int, int> in_post_index_map_;
    int in_len_;
    int post_len_;
};


int main(int argc, char* argv[]) { return 0; }