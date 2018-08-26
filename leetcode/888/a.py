class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sumA = sum(A)
        sumB = sum(B)
        # print(sumA, sumB)
        minus = sumB - sumA
        mapB = {}
        for i in B:
            mapB[i] = 1
        for x in A:
            if minus // 2 + x in mapB:
                return [x, minus // 2 + x]


print(Solution().fairCandySwap([1, 1], [2, 3]))
