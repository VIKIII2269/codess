class Solution:
    def isValid(self, s: str) -> bool:
        x=s.count(")")
        x2=s.count("(")
        y=s.count("{")
        y2=s.count("}")
        z=s.count("[")
        z2=s.count("]")
        stack=[]

        if x != x2 or y != y2 or z != z2:
            return False
        else:
            
            for a in s:
                if a in "({[":
                    stack.append(a)
                elif a == ")" and (stack and stack[-1] == '('):
                    stack.pop()
                elif a == "}" and (stack and stack[-1] == '{'):
                    stack.pop()
                elif a == "]" and (stack and stack[-1] == '['):
                    stack.pop()
            if len(stack)==0:
                return True 
            else :
                return False




            