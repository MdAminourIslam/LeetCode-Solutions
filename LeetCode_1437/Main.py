from typing import List

class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if (k == 0):
            return True
        last = -1
        for i in range(n):
            if (nums[i] == 1):
                if (last == -1): 
                    last = i
                else:
                    if (i - last - 1 < k):
                        return False
                    last = i
        return True