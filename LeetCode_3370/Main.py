class Solution(object):
    def smallestNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        import math
        last = int(math.log2(n))
        return (1 << (last + 1)) - 1


