class Solution:
    def extractDiagonal(self, mat, row, col):
        diagonal = []
        n = len(mat)
        m = len(mat[0])
        while row < n and col < m:
            diagonal.append(mat[row][col])
            row += 1
            col += 1
        return diagonal

    def insertDiagonal(self, mat, diagonal, row, col):
        idx = 0
        n = len(mat)
        m = len(mat[0])
        while row < n and col < m:
            mat[row][col] = diagonal[idx]
            idx += 1
            row += 1
            col += 1

    def diagonalSort(self, mat):
        n = len(mat)
        m = len(mat[0])

        for i in range(n):
            diagonal = self.extractDiagonal(mat, i, 0)
            diagonal.sort()
            self.insertDiagonal(mat, diagonal, i, 0)

        for j in range(1, m):
            diagonal = self.extractDiagonal(mat, 0, j)
            diagonal.sort()
            self.insertDiagonal(mat, diagonal, 0, j)

        return mat




