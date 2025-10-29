from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        xorResult = 0
        for num in nums:
            xorResult ^= num
        
        flip = 0
        
        for i in range(31):
            if (xorResult & (1 << i)) != (k & (1 << i)):
                flip += 1
        return flip