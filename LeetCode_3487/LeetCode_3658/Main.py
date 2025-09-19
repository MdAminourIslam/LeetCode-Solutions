from math import gcd
class Solution(object):
    def gcdOfOddEvenSums(self, n):
        """
        :type n: int
        :rtype: int
        """
        sumOdd = n * n
        sumEven = n * (n + 1)
        return gcd(sumOdd, sumEven)

sol = Solution()
print(sol.gcdOfOddEvenSums(4))