import math
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0: return False
        last = int(math.log2(n))
        return (last % 2 == 0) and ((1 << last) == n)


sol = Solution()
print(sol.isPowerOfFour(10))
