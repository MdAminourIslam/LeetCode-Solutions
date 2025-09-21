class Solution(object):
    def evenNumberBitwiseORs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        answer = 0
        for num in nums:
            if not (num & 1):
                answer |= num
        return answer
