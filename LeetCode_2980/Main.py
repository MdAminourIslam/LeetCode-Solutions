class Solution(object):
    def hasTrailingZeros(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        evenCnt = 0
        for num in nums:
            if num % 2 == 0:
                evenCnt += 1
            
            if evenCnt > 1:
                return True
        return False