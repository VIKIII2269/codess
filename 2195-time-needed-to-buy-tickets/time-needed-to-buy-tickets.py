from collections import deque

class Solution:

    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        t=0
        s=0
      


        for i in range(0,len(tickets)):
                if i<=k:
                    if tickets[i]>=tickets[k]:
                        s+=tickets[k]
                    else:
                        s+=tickets[i]
                else:
                    if tickets[i]>=tickets[k]:
                        s+=tickets[k]-1
                    else:
                        s+=tickets[i] 
        return s




            
