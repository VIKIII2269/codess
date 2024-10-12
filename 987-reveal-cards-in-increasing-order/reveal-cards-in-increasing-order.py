from collections import deque
dq = deque()
dq.append(10)  
dq.appendleft(20) 
item = dq.pop() 
item = dq.popleft() 
size = len(dq)
dq.rotate(1)  
dq.rotate(-1)  

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
       q=deque(deck)
       r=[]
       deck.sort()
       result=deque()
       for card in reversed(deck):
            if result:
                
                result.appendleft(result.pop())
            
            result.appendleft(card)

       
       return list(result)
       



       



