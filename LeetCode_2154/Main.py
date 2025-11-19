from typing import List

class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        while original in nums:
            original *= 2
        return original

print(Solution().findFinalValue(nums = [5,3,6,1,12], original = 3))
print(Solution().findFinalValue(nums = [2,7,9], original = 4))