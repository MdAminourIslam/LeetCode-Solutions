class Solution(object):
    def numSubmat(self, matrix):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        n = len(matrix)
        m = len(matrix[0])
        right_ones = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(n):
            col = m - 1
            ones = 0
            while col >= 0:
                if matrix[i][col]:
                    ones += 1
                else:
                    ones = 0
                right_ones[i][col] = ones
                col -= 1
            
        answer = 0
        for i in range(n):
            for j in range(m):
                minimun = m
                for k in range(i, n):
                    minimun = min(minimun, right_ones[k][j])
                    answer += minimun
        return answer


