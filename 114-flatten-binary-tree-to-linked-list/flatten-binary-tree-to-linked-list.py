class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        
        # Flatten the left and right subtrees
        self.flatten(root.left)
        self.flatten(root.right)
        
        # Store the left and right children
        left = root.left
        right = root.right
        
        # Set the left subtree to None and the right subtree to the flattened left subtree
        root.left = None
        root.right = left
        
        # Move to the end of the new right subtree (which was the left subtree)
        current = root
        while current.right:
            current = current.right
        
        # Attach the original right subtree to the end of the new right subtree
        current.right = right
