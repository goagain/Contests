class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        ans = -1
        startPos = 0
        endPos = 0
        s = 0
        triggerd = False
        while endPos < len(A):
            while s < 0 and startPos < endPos:
                s -= A[startPos]
                startPos += 1
            if s >= K:
                triggerd = True
            while triggerd and startPos < endPos:
                if (ans == -1 or endPos - startPos < ans) and s >= K:
                    ans = endPos - startPos
                s -= A[startPos]
                startPos += 1
            if endPos < len(A):
                s += A[endPos]
                endPos += 1
        while startPos < len(A):
            if (ans == -1 or endPos - startPos < ans) and s >= K:
                ans = endPos - startPos
            s -= A[startPos]
            startPos += 1
        return ans

print(Solution().shortestSubarray([1], 1))
print(Solution().shortestSubarray([1, 2], 4))
print(Solution().shortestSubarray([2, -1, 2], 3))
print(Solution().shortestSubarray([2, 2], 0))
print(Solution().shortestSubarray([84,-37,32,40,95], 167))
print(Solution().shortestSubarray([-34,37,51,3,-12,-50,51,100,-47,99,34,14,-13,89,31,-14,-44,23,-38,6], 151))
