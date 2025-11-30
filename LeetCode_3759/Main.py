class Solution(object):
    def countElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        if not k:
            return n
        
        nums.sort()
        cnt = 0
        for num in nums:
            if num < nums[n - k]:
                cnt += 1
        return cnt