/**
 * Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from the
root node down to the farthest leaf node.

Note: A leaf is a node with no children.
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
#include <string>
#include <vector>
#include "utils/include/btree.h"

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
   public:
    int maxDepth(TreeNode *root) {
        int left_depth = 0;
        int right_depth = 0;

        if (NULL == root) {
            return 0;
        }
        left_depth = maxDepth(root->left);
        right_depth = maxDepth(root->right);

        return left_depth >= right_depth ? (left_depth + 1) : (right_depth + 1);
    }

    int maxDepth1(TreeNode *root) {
        int left_depth = 0;
        int right_depth = 0;

        if (NULL == root) {
            return 0;
        }

        // 这种做法，会导致搜索完root->left后，可能会再去搜索root->right，导致次数多了一次
        if (NULL != root->left) {
            FindNextChild(root->left, ++left_depth, right_depth);
        }

        if (NULL != root->right) {
            FindNextChild(root->right, left_depth, ++right_depth);
        }

        return left_depth >= right_depth ? (left_depth + 1) : (right_depth + 1);
    }

    template <typename T>
    void create_binary_tree(TreeNode *root, vector<T> tree_vals) {
        // for (auto node : tree_vals) {
        //     root = new TreeNode;
        //         }
    }

   private:
    void FindNextChild(TreeNode *root, int &left_depth, int &right_depth) {
        if (NULL == root) {
            return;
        }
        if (NULL != root->left) {
            FindNextChild(root->left, ++left_depth, right_depth);
        }

        if (NULL != root->right) {
            FindNextChild(root->right, left_depth, ++right_depth);
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> value{3, 9, 20, 15, 7};
    BTree tree(value);
    tree.print();

    Solution sln;
    auto depth = sln.maxDepth(tree.get_tree());
    cout << "depth = " << depth << endl;

    return 0;
}