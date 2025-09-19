import math
class Solution(object):
    def beautifulSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        cnt = defaultdict(int)
        cnt[0] = 1
        xor = 0
        subArray = 0
        for i in nums:
            xor ^= i
            if cnt[xor] > 0:
                subArray += cnt[xor]
            cnt[xor] += 1
        return subArray
