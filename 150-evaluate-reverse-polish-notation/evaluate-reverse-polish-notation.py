from collections import deque

class Solution:
    def evalRPN(self, t: list[str]) -> int:
        s = deque()

        for a in t:
            if a.isdigit() or (a[0] == '-' and len(a) > 1):  # Handle negative numbers as well
                s.append(int(a))
            else:
                b = s.pop()  # Second operand
                c = s.pop()  # First operand

                if a == "+":
                    s.append(c + b)
                elif a == "-":
                    s.append(c - b)
                elif a == "*":
                    s.append(c * b)
                elif a == "/":
                    # Integer division like in RPN, needs to handle negatives correctly.
                    s.append(int(c / b))  # Python division returns float, so convert to int

        return s.pop()  # The result will be the last remaining item on the stack
