# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
      
        def help(root,curr)->bool:
         if not root:
            return False
         curr+=root.val
         if not root.right and not root.left:
            return curr==targetSum
         return (help(root.right,curr) or help(root.left,curr))
        return help(root,0)