# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        if root==p or root==q:
            return root
        

        l1=self.lowestCommonAncestor(root.left,p,q)
        l2=self.lowestCommonAncestor(root.right,p,q)
        if l1 and l2:
            return root
        if l1:
            return l1
        else:
            return l2
