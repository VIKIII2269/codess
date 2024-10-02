# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def solve(root)-> int:
            if not root:
                return 0
            return 1+ solve(root.left)+solve(root.right)
        k=solve(root)
        return k