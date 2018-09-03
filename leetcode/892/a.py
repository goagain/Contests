class Solution:
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans = 0
        ans = sum([j != 0 for i in grid for j in i]) * 2
        for i, row in enumerate(grid):
            for j, column in enumerate(row):
                if j == 0:
                    ans = ans + column
                else:
                    ans = ans + max(0, row[j] - row[j-1])
                if j == len(row)-1:
                    ans = ans + column
                else:
                    ans = ans + max(0, row[j] - row[j+1])
        for i, row in enumerate(grid):
            for j, column in enumerate(row):
                if i == 0:
                    ans += column
                else:
                    try:
                        ans += max(0, grid[i][j] - grid[i-1][j])
                    except:
                        ans += grid[i][j]
                if i == len(grid)-1:
                    ans += column
                else:
                    try:
                        ans += max(0, grid[i][j] - grid[i+1][j])
                    except:
                        ans += grid[i][j]
        return ans

print(Solution().surfaceArea([[1,1,1],[1,0,1],[1,1,1]]))