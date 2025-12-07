class Solution(object):
    def countOdds(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        def func(n):
            return (n + 1) // 2
        return func(high) - func(low - 1)