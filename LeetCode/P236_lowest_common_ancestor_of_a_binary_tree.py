#
#  Definition for a binary tree node.

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None or p is None or q is None:
            return None
        self.res_ = None

        self.LCA(root, p, q)

        return self.res_
    
    def LCA(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> bool:
        if root is None:
            return False

        left_num = 1 if self.LCA(root.left, p, q) else 0
        right_num = 1 if self.LCA(root.right, p, q) else 0
        mid_num = 1 if root == p or root == q else 0

        if left_num + right_num + mid_num >= 2:
            self.res_ = root
            return True
        
        return left_num + right_num + mid_num >= 1


if __name__ == "__main__":
    pass
        

