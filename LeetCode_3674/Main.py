class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums.count(nums[0]) == len(nums):
            return 0
        else:
            return 1

