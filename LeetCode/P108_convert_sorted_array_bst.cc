/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        if (0 == len) {
            return NULL;
        }

        return Dfs(nums, 0, len - 1);
    }

   private:
    TreeNode* Dfs(const vector<int>& nums, int left, int right) {
        if (left > right) return NULL;

        int mid = (left + right) / 2;
        if (mid < 0 || mid >= nums.size()) {
            return NULL;
        }

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Dfs(nums, left, mid - 1);
        root->right = Dfs(nums, mid + 1, right);

        return root;
    }
};