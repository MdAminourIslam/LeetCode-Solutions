# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        cnt = dict()
        for num in nums:
            if num in cnt:
                cnt[num] += 1
            else:
                cnt[num] = 1
        
        result = resultHead = None

        while head:
            if not head.val in cnt:
                if resultHead:
                    result.next = head
                    result = result.next
                else:
                    result = resultHead = head
            head = head.next
        
        result.next = None
        return resultHead

