#ifndef BTREE_H_
#define BTREE_H_

#include <vector>

// definition for a binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BTree {
   public:
    BTree() {}
    BTree(std::vector<int>& values);
    ~BTree() {}


    TreeNode* insert_order(const std::vector<int>& values, int left, int right);
    void insert(int ele);
    void insert(int ele, TreeNode*& parent);
    void print();

    inline bool is_empty() { return (nullptr == root); }
    inline TreeNode* get_tree() { return root; }

   private:
    void print_tree(TreeNode* root);

   private:
    TreeNode* root;
};

#endif