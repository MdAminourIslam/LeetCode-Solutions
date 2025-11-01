from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        resultHead = current = None

        while head:
            if head.val != val:
                if resultHead:
                    current.next = head
                    current = current.next
                else:
                    resultHead = head
                    current = head
            head = head.next
        
        if resultHead:
            current.next = None
        
        return resultHead