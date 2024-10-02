# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def solve(root):
            if not root:
                return 0
            lh=solve(root.left)
            if lh==-1:
                return -1
            rh=solve(root.right)
            if rh==-1:
                return -1
            if abs(lh-rh)>1:
                return -1
            else :
                return max(rh,lh)+1
        k=solve(root)
        if k ==-1 :
            return False 
        else :
            return True
            