class Solution(object):
    def dfs(self, i, j, triangle, dp, n, inf):
        if i + 1 == n:  
            return triangle[i][j]
        
        if dp[i][j] != inf:
            return dp[i][j]
        
        choice1 = self.dfs(i + 1, j, triangle, dp, n, inf)
        choice2 = self.dfs(i + 1, j + 1, triangle, dp, n, inf)
    
        dp[i][j] = triangle[i][j] + min(choice1, choice2)
        return dp[i][j]

    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        inf = 10**9
        n = len(triangle)
        dp = [[inf for _ in range(n)] for _ in range(n)]

        return self.dfs(0, 0, triangle, dp, n, inf)
