class Solution(object):
    def sumOfUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = [0 for _ in range(101)]
        for num in nums:
            cnt[num] += 1
        return sum(i for i in range(1, 101) if cnt[i] == 1)