class Solution:
    def extractDiagonal(self, grid, row, col):
        diagonal = []
        n = len(grid)
        while row < n and col < n:
            diagonal.append(grid[row][col])
            row += 1
            col += 1
        return diagonal

    def insertDiagonal(self, grid, diagonal, row, col):
        idx = 0
        n = len(grid)
        while row < n and col < n:
            grid[row][col] = diagonal[idx]
            idx += 1
            row += 1
            col += 1

    def sortMatrix(self, grid):
        n = len(grid)

        for i in range(n):
            diagonal = self.extractDiagonal(grid, i, 0)
            diagonal.sort(reverse=True)   # Sort descending
            self.insertDiagonal(grid, diagonal, i, 0)

        for j in range(1, n):
            diagonal = self.extractDiagonal(grid, 0, j)
            diagonal.sort()   # Sort ascending
            self.insertDiagonal(grid, diagonal, 0, j)

        return grid




