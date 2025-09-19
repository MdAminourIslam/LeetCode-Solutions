from typing import List
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        prefix = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(n):
            for j in range(m):
                prefix[i][j] = matrix[i][j]
                if i > 0:
                    prefix[i][j] += prefix[i - 1][j]
                if j > 0:
                    prefix[i][j] += prefix[i][j - 1]
                if i > 0 and j > 0:
                    prefix[i][j] -= prefix[i - 1][j - 1]
        answer = 0
        for size in range(min(n, m)):
            for i in range(n):
                for j in range(m):
                    if i + size >= n or j + size >= m:
                        break
                    sum = prefix[i + size][j + size]
                    if i > 0:
                        sum -= prefix[i - 1][j + size]
                    if j > 0:
                        sum -= prefix[i + size][j - 1]
                    if i > 0 and j > 0:
                        sum += prefix[i - 1][j - 1]
                    if sum == (size + 1) * (size + 1):
                        answer += 1
        return answer

                    