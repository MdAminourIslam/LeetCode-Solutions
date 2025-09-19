def generatePascal(i, dp):
    if i == 0:
        dp[0] = [1]
        return
    if not dp[i - 1]:
        generatePascal(i - 1, dp)
    
    dp[i] = [1 for _ in range(i + 1)]
    for j in range(1, i):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
        
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        dp = [[] for _ in range(numRows)]
        self.generatePascal(numRows - 1, dp)
        return dp
    

s1 = Solution()
print(s1.generate(5))