class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(nums)
        cnt = 0
        ans = 1
        for num in nums:
            if num == mx:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans