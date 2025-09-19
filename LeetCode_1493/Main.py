class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        prefix = [0 for _ in range(n + 1)]
        suffix = [0 for _ in range(n + 1)]

        ones = 0
        for i in range(n):
            if nums[i]:
                ones += 1
            else:
                ones = 0
            prefix[i] = ones
        
        ones = 0
        for i in range(n - 1, -1, -1):
            if nums[i]:
                ones += 1
            else:
                ones = 0
            suffix[i] = ones
        
        answer = 0
        for i in range(n):
            if not i:
                answer = max(answer, suffix[i + 1])
            elif i + 1 == n:
                answer = max(answer, prefix[i - 1])
            else:
                answer = max(answer, prefix[i - 1] + suffix[i + 1])
        
        return answer

