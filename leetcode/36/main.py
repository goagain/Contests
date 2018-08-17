class Solution:
    board = None

    def CheckRow(self, x, y):
        for i in range(9):
            if i != y and self.board[x][i] == self.board[x][y]:
                return False
        return True

    def CheckColumn(self, x, y):
        for i in range(9):
            if i != x and self.board[i][y] == self.board[x][y]:
                return False
        return True

    def CheckCell(self, x, y):
        cellList = [(i, j) for i in range(3) for j in range(3)]
        cellFirst = (x // 3 * 3, y // 3 * 3)
        for p in cellList:
            newPoint = (cellFirst[0] + p[0], cellFirst[1] + p[1])
            if newPoint != (x, y) and self.board[newPoint[0]][newPoint[1]] == self.board[x][y]:
                return False
        return True

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        self.board = board
        for i in range(9):
            for j in range(9):
                if self.board[i][j] != ".":
                    if self.CheckRow(i, j) and self.CheckColumn(i, j) and self.CheckCell(i, j):
                        continue
                    else:
                        print("error on grid %d %d" % (i, j))
                        return False
        return True

l = [
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
l2 = [
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
print(Solution().isValidSudoku(l))
print(Solution().isValidSudoku(l2))