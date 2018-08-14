class Solution:
    def getRow(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        line = list()
        c = 1
        line.append(c)
        for j in range(1,numRows+1):
            c = int(c * (numRows-j+1) / (j))
            line.append(c)
        return line

[print(Solution().getRow(x)) for x in range(20)]

