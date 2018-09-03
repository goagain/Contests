class Solution:
    mod = 10**9+7
    def sumSubseqWidths(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.sort()
        ans = 0
        for i, x in enumerate(A):
            ans = (ans + x * pow(2, i, self.mod) - x * pow(2, len(A)-i-1, self.mod)) % self.mod
        return ans
print(Solution().sumSubseqWidths([1,2,3]))