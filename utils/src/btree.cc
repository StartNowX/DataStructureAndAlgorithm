#include "utils/include/btree.h"
#include <algorithm>
#include <iostream>

BTree::BTree(std::vector<int>& values) {
    root = nullptr;
    std::sort(values.begin(), values.end());
    root = insert_order(values, 0, values.size() - 1);
}

TreeNode* BTree::insert_order(const std::vector<int>& values, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = (left + right + 1) / 2;
    TreeNode* new_root_node = new TreeNode(values[mid]);
    new_root_node->left = insert_order(values, left, mid - 1);
    new_root_node->right = insert_order(values, mid + 1, right);
    return new_root_node;
}

void BTree::insert(int ele) { insert(ele, root); }

void BTree::insert(int ele, TreeNode*& parent) {
    if (nullptr == parent) {
        parent = new TreeNode(ele);
        return;
    } else {
        if (ele > parent->val) {
            return insert(ele, parent->right);

        } else if (ele < parent->val) {
            return insert(ele, parent->left);
        } else {
            return;
        }
    }
}

void BTree::print() {
    print_tree(root);
    std::cout << std::endl;
}

void BTree::print_tree(TreeNode* root) {
    if (root != nullptr) {
        print_tree(root->left);
        std::cout << root->val << " ";
        print_tree(root->right);
    }
}