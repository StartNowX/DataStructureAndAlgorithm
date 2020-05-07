# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s and not t:
            return True
        if (not s and t) or (s and not t):
            return False

        return self.isSubtreeCore(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def isSubtreeCore(self, s: TreeNode, t: TreeNode) -> bool:
        if not s and not t:
            return True
        if (not s and t) or (s and not t) or s.val != t. val:
            return False
        
        return self.isSubtreeCore(s.left, t.left) and self.isSubtreeCore(s.right, t.right)

if __name__ == "__main__":
    return 0