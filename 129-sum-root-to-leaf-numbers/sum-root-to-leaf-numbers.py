class Solution:
    def depth(self, root) -> int:
        if not root:
            return 0
        return max(self.depth(root.left), self.depth(root.right)) + 1

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        s = 0 

        def solve(root, d, v):
            nonlocal s 
            if not root:
                return

            m = root.val
            v = v * 10 + m  
            
            
            if not root.right and not root.left:
                s += v
                return

           
            solve(root.left, d - 1, v)
            solve(root.right, d - 1, v)

        d = self.depth(root) 
        solve(root, d, 0)
        return s
