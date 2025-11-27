class Solution(object):
    def maxSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        # min prefix for each remainder
        minPrefix = [float("inf")] * k
        minPrefix[0] = 0

        ans = float("-inf")

        for i in range(1, n + 1):
            rem = i % k

            # Try using previous minimum prefix of same remainder
            if minPrefix[rem] != float("inf"):
                ans = max(ans, prefix[i] - minPrefix[rem])

            # Update min prefix for this remainder
            minPrefix[rem] = min(minPrefix[rem], prefix[i])

        return ans


