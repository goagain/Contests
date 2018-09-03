from functools import cmp_to_key
class Solution:
    searchCount = 0
    board = None
    unknownList = None
    solved = False
    
    rows = []
    colunms = []
    grids = []
    def CheckRow(self, x, y, c):
        return not c in self.rows
        # for i in range(9):
        #     if i != y and self.board[x][i] == self.board[x][y]:
        #         return False
        # return True

    def CheckColumn(self, x, y, c):
        return not c in self.colunms
        # for i in range(9):
        #     if i != x and self.board[i][y] == self.board[x][y]:
        #         return False
        # return True

    def CheckCell(self, x, y, c):
        cellList = [(i, j) for i in range(3) for j in range(3)]
        cellFirst = (x // 3 * 3, y // 3 * 3)
        for p in cellList:
            newPoint = (cellFirst[0] + p[0], cellFirst[1] + p[1])
            if newPoint != (x, y) and self.board[newPoint[0]][newPoint[1]] == str(c):
                return False
        return True

    def Check(self, x, y, c):
        return self.CheckRow(x, y, c) and self.CheckColumn(x, y, c) and self.CheckCell(x, y, c)

    def dfs(self, index):
        if self.solved:
            return
        if index >= len(self.unknownList):
            self.solved = True
            return
        x, y = self.unknownList[index]
        self.searchCount = self.searchCount + 1
        print("%d %d" %(self.searchCount, index))
        for i in range(9):
            if self.Check(x, y, i):
                self.board[x][y] = str(i)
                self.rows[x].add(str(i))
                self.colunms[y].add(str(i))
                self.dfs(index + 1)
                self.rows[x].remove(str(i))
                self.colunms[y].remove(str(i))
                self.board[x][y] = '.'
            if self.solved:
                return
        self.board[x][y] = '.'

    def getValidCount(self, index):
        x, y = index
        if self.board[x][y] != ".":
            return 0
        count = 0
        for i in range(9):
            if self.Check(x, y, i):
                count = count + 1
        return count

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.board = board
        for i in range(9):
            m = set()
            for c in self.board[i]:
                if c != '.':
                    m.add(c)
            self.rows.append(m)
        for i in range(9):
            m = set()
            for j in range(9):
                c = self.board[j][i]
                if c != '.':
                    m.add(c)
            self.colunms.append(m)

        self.unknownList = [(x,y) for x in range(9) for y in range (9) if self.board[x][y] == '.']
        self.unknownList.sort()
        def cmp(a,b):
            return self.getValidCount(a) - self.getValidCount(b)
        self.unknownList = sorted(self.unknownList, key = cmp_to_key(cmp))
        self.dfs(0)
        return self.board

board = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]]
print(Solution().solveSudoku(board))