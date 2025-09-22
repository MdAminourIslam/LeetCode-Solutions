class Solution(object):
    def maxFrequencyElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = [0 for _ in range(101)]
        for num in nums:
            cnt[num] += 1
        mx = max(cnt)
        sum = 0
        for c in cnt:
            if c == mx:
                sum += c 
        return sum