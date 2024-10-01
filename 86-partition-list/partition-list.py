# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less_head = ListNode(0)  # Linked list for nodes < x
        greater_head = ListNode(0)  # Linked list for nodes >= x
        
        # Pointers to build the new linked lists
        less = less_head
        greater = greater_head
        
        # Traverse the original list
        while head:
            if head.val < x:
                less.next = head  # Append to the 'less' list
                less = less.next
            else:
                greater.next = head  # Append to the 'greater' list
                greater = greater.next
            head = head.next  # Move to the next node
        
        
        greater.next = None 
        less.next = greater_head.next 
        return less_head.next