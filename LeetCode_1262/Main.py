from typing import List

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        tot = sum(nums)
        b, c = [], []
        
        for x in nums:
            if x % 3 == 1:
                b.append(x)
            elif x % 3 == 2:
                c.append(x)
        
        b.sort()
        c.sort()

        if tot % 3 == 0:
            return tot

        if tot % 3 == 1:
            op1 = tot - b[0] if len(b) > 0 else 0
            op2 = tot - c[0] - c[1] if len(c) > 1 else 0
            return max(op1, op2)
        else:
            op1 = tot - b[0] - b[1] if len(b) > 1 else 0
            op2 = tot - c[0] if len(c) > 0 else 0
            return max(op1, op2)
