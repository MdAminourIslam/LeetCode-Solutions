from typing import List


class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        mod = 10**9 + 7
        n, m = len(grid), len(grid[0])
        dp = [[[0] * k for _ in range(m)] for __ in range(n)]

        dp[0][0][grid[0][0] % k] = 1

        for i in range(n):
            for j in range(m):
                if i > 0:
                    for kk in range(k):
                        val = dp[i - 1][j][kk]
                        if val:
                            new_rem = (kk + grid[i][j]) % k
                            dp[i][j][new_rem] = (dp[i][j][new_rem] + val) % mod
    
                if j > 0:
                    for kk in range(k):
                        val = dp[i][j - 1][kk]
                        if val:
                            new_rem = (kk + grid[i][j]) % k
                            dp[i][j][new_rem] = (dp[i][j][new_rem] + val) % mod

        return dp[n - 1][m - 1][0]