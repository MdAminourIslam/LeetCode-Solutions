class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        ans = 0
        for num in nums:
            if num == 0:
                cnt += 1
            else:
                ans += int(cnt * (cnt + 1) / 2)
                cnt = 0
        ans += int(cnt * (cnt + 1) / 2)
        return ans