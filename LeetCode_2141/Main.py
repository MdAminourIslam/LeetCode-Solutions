class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        def good(T):
            total = 0
            for b in batteries:
                total += min(b, T)
                if total >= n * T:
                    return True
            return total >= n * T

        lo, hi = 0, sum(batteries) // n
        ans = 0

        while lo <= hi:
            mid = (lo + hi) // 2
            if good(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans
