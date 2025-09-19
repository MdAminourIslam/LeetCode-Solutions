class Solution:
    def findDiagonalOrder(self, mat):
        m, n = len(mat), len(mat[0])
        diagonals = [[] for _ in range(m + n - 1)]
        
        for i in range(m):
            for j in range(n):
                diagonals[i + j].append(mat[i][j])
        
        answer = []
        for d in range(len(diagonals)):
            if d % 2 == 0:
                answer.extend(reversed(diagonals[d]))
            else:
                answer.extend(diagonals[d])
        
        return answer

# Testing:
sol = Solution()
mat = [[1,2,3],[4,5,6],[7,8,9]]
print(sol.findDiagonalOrder(mat))

mat = [[1,2],[3,4]]
print(Solution().findDiagonalOrder(mat))
