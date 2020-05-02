# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root: TreeNode):
        if root is None:
            return 0
        return max(self.robcore(root))
        
    '''返回list，[当前节点不参与计算的最大收益，当前节点的最大收益（参与/不参与）]'''
    def robcore(self, root: TreeNode):
        if root is None:
            return [0, 0]
        left_amount = self.robcore(root.left)
        right_amount = self.robcore(root.right)
        cur_node_take = root.val + left_amount[0] + right_amount[0]
        cur_node_notake = left_amount[1] + right_amount[1]
        return [cur_node_notake, max(cur_node_take, cur_node_notake)]

if __name__ == "__main__":
    sln = Solution()
    node1, node2 = TreeNode(3), TreeNode(5)
    root = TreeNode(1)
    root.left, root.right = node1, node2

    money = sln.rob(root)
    print("money = ", money)
    