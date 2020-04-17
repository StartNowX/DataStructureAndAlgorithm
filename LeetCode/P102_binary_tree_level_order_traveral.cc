/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

    3
   / \
  9  20
    /  \
   15   7

   [
        [3],
        [9,20],
        [15,7]
    ]
*/

#include <iostream>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return res_;
        }

        Bfs(root, 0);

        return res_;
    }

   private:
    void Bfs(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }

        int exist_len = static_cast<int>(res_.size());
        if (exist_len == level) {
            res_.emplace_back(vector<int>{});
        }

        res_[level].emplace_back(root->val);

        if (root->left != NULL) {
            Bfs(root->left, level + 1);
        }
        if (root->right != NULL) {
            Bfs(root->right, level + 1);
        }
    }

   private:
    vector<vector<int>> res_;
};

int main(int argc, char* argv[]) { return 0; }