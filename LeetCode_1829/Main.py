class Solution(object):
    def getMaximumXor(self, nums, maximumBit):
        """
        :type nums: List[int]
        :type maximumBit: int
        :rtype: List[int]
        """
        mx = (1 << maximumBit) - 1
        n = len(nums)
        pre_xor = [0] * n
        ans = [0] * n
        
        pre_xor[0] = nums[0]
        for i in range(1, n):
            pre_xor[i] = pre_xor[i - 1] ^ nums[i]
        
        for i in range(n):
            ans[i] = pre_xor[n - i - 1] ^ mx
        
        return ans
