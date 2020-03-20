class Solution:
    def getOrd(self, c : str):
        return ord(c)

    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        count = [0] * 256
        for c in t:
            count[self.getOrd(c)] += 1

        bestStart = -1
        bestEnd = len(s)
        start = 0
        cur = 0
        for cur in range(len(s)):
            count[self.getOrd(s[cur])] -= 1
            while all(x <= 0 for x in count) and start <= cur:
                if cur + 1 - start < bestEnd - bestStart:
                    bestStart, bestEnd = start, cur + 1
                count[self.getOrd(s[start])] += 1
                start += 1
            else:
                continue
        if bestStart != -1:
            return s[bestStart:bestEnd]
        else:
            return ""

print(Solution().minWindow("ADOBECODEBANC","ABC"))
print(Solution().minWindow("ADOBECODEBANC",""))
print(Solution().minWindow("ADOBECODEBANC","F"))