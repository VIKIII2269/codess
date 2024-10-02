# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    





    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def help(left,right)->bool:
         if not left and not right:
            return True
         if not left or not right:
            return False
         return((left.val==right.val) and help(left.left,right.right)and help(left.right,right.left))
         
        
        return help(root.left,root.right)
            
