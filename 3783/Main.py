class Solution:
    def reverseNumber(self, n: int) -> int:
        revNum = 0
        while n > 0:
            revNum = revNum * 10 + (n % 10)
            n //= 10
        return revNum

    def mirrorDistance(self, n: int) -> int:
        return abs(self.reverseNumber(n) - n)