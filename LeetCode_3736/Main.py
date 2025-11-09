class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(nums)
        s = sum(nums)
        return (len(nums) * mx) - s