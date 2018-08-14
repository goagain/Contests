class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = []
        for i in range(numRows):
            if i == 0:
                ans.append([1])
                continue
            line = list()
            c = 1
            line.append(c)
            for j in range(1,i+1):
                c = int(c * (i-j+1) / (j))
                line.append(c)
            ans.append(line)
        return ans

print(Solution().generate(20))
