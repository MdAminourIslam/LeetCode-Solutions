class Solution(object):
    
    def helper(self, board, topi, topj):
        seen = set()
        for i in range(3):
            for j in range(3):
                 if board[i + topi][j + topj] != '.':
                    if board[i + topi][j + topj] in seen:
                        return False
                    seen.add(board[i + topi][j + topj])
        return True
            
    def isValidSudoku(self, board):

        for i in range(9):
            seen = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in seen:
                        return False
                    seen.add(board[i][j])

        for i in range(9):
            seen = set()
            for j in range(9):
                if board[j][i] != '.':
                    if board[j][i] in seen:
                        return False
                    seen.add(board[j][i])
        
        ok = True
        ok = ok and self.helper(board, 0, 0)
        ok = ok and self.helper(board, 0, 3)
        ok = ok and self.helper(board, 0, 6)

        ok = ok and self.helper(board, 3, 0)
        ok = ok and self.helper(board, 3, 3)
        ok = ok and self.helper(board, 3, 6)

        ok = ok and self.helper(board, 6, 0)
        ok = ok and self.helper(board, 6, 3)
        ok = ok and self.helper(board, 6, 6)
        
        return ok
        

