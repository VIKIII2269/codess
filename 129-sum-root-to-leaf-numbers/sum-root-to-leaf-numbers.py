class Solution:
   
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        s = 0 

        def solve(root, v):
            nonlocal s 
            if not root:
                return

            m = root.val
            v = v * 10 + m  
            
            
            if not root.right and not root.left:
                s += v
                return

           
            solve(root.left,  v)
            solve(root.right, v)

        solve(root, 0)
        return s
