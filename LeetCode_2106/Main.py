class Solution(object):
    def maxTotalFruits(self, fruits, startPos, k):
        """
        :type fruits: List[List[int]]
        :type startPos: int
        :type k: int
        :rtype: int
        """
        mx = 200000 + 2
        pre_sum = [0] * mx

        # fruits[position][amount]
        for temp in fruits:
            pre_sum[temp[0] + 1] = temp[1]

        # Prefix sum
        for i in range(1, mx):
            pre_sum[i] += pre_sum[i - 1]

        ans = 0
        startPos += 1  # Shift to match pre_sum index

        # Move left first
        for i in range(k + 1):
            left = max(startPos - i, 1)
            right = min(left + k - i, 200001)
            ans = max(ans, pre_sum[right] - pre_sum[left - 1])

        # Move right first
        for i in range(k + 1):
            right = min(startPos + i, 200001)
            left = max(right - (k - i), 1)
            ans = max(ans, pre_sum[right] - pre_sum[left - 1])

        return ans
        