import math
class Solution(object):
    def countTriples(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0

        for a in range(1, n + 1):
            for b in range(1, n + 1):
                c = int(math.sqrt(a * a + b * b))
                if c <= n and c * c == a * a + b * b:
                    res += 1

        return res