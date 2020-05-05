# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True

        def helper(root: TreeNode, lower: float, higher: float) -> bool:
            if root is None:
                return True
            
            if root.val <= lower or root.val >= higher:
                return False

            return helper(root.left, lower, root.val) and helper(root.right, root.val, higher)

        return helper(root, -float('inf'), float('inf'))

if __name__ == "__main__":
    sln = Solution()