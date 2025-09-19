class Solution(object):
    def flowerGame(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        res = 0
        for i in range(n):
            x = i + 1
            if x % 2 == 0:
                res += (m + 1) // 2
            else:
                res += m // 2
        return res
