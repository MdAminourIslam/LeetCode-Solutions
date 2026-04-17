from typing import List

class Solution:
    def reverseNumber(self, n: int) -> int:
        revNum = 0
        while n > 0:
            revNum = revNum * 10 + (n % 10)
            n //= 10
        return revNum
    
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        indx = {}
        n = len(nums)
        answer = n
        
        for i in range(n):
            if nums[i] in indx:
                answer = min(answer, i - indx[nums[i]] + 1)
            rev = self.reverseNumber(nums[i])
            indx[rev] = i + 1
        
        return answer if answer != n else -1