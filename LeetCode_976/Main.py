class Solution(object):
    def largestPerimeter(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        mx = 0
        for i in range(n - 2):
            if nums[i] + nums[i + 1] > nums[i + 2]:
                mx = nums[i] + nums[i + 1] + nums[i + 2]
        return mx

