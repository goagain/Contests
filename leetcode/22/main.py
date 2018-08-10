class Solution(object):
    ans = []
    tmpString = []

    def dfs(self, n, l, r):
        if l == n and r == n:
            self.ans.append(''.join(self.tmpString))
        if l < n:
            self.tmpString[l + r] = '('
            self.dfs(n, l + 1, r)
        if r < l:
            self.tmpString[l + r] = ')'
            self.dfs(n, l, r + 1)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.ans = []
        self.tmpString = [0 for x in range(2*n)]
        self.dfs(n, 0, 0)
        return self.ans


print(Solution().generateParenthesis(3))
