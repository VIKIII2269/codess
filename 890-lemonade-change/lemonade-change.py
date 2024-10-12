class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        f=0
        t=0
        w=0
        for i in bills:
            if i==5:
                f+=1
            elif i==10:
                if f>=1:
                    t+=1
                    f-=1
                else:
                    return False
            else:
                if (t>=1 and f>=1):
                    t=t-1
                    f=f-1
                    w=w+1
                elif f>=3:
                    f=f-3
                    w=w+1
                else:
                    return False
        return True

                

