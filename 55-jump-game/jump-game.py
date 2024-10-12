class Solution:
    def canJump(self, nums: List[int]) -> bool:
        num = 0
        if num not in nums:
            return True
        if len(nums)==1 or len(nums)==0:
            return True
        if nums[0]==0:
            return False




        mi=0
        a=0
        s=0
        for i in range (0,len(nums)):
            if (i>mi):
                return False
            a=nums[i]+i
            
            mi=max(mi,a)
        if mi>=len(nums)-1:
            return True 
        else:
            return False
