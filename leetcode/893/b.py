class Solution:
    def getHash(self, s):
        array1 = [c for i, c in enumerate(s) if i % 2 == 0]
        array1.sort()
        array2 = [c for i, c in enumerate(s) if i % 2 == 1]
        array2.sort()
        return "".join(array1) + "#" + "".join(array2)
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        ss = set()
        for s in A:
            ts = self.getHash(s)
            if s not in ss:
                ss.add(ts)
        return len(ss)

print(Solution().numSpecialEquivGroups(["abc","acb","bac","bca","cab","cba"]))