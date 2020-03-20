class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        count = {}
        for c in t:
            if c in count:
                count[ord(c)] += 1
            else:
                count[ord(c)] = 1
        bestStart = -1
        bestEnd = len(s)
        start = 0
        cur = 0
        skipCheck = False
        for cur in range(len(s)):
            if ord(s[cur]) in count:
                count[ord(s[cur])] -= 1
            else:
                continue
            skipCheck = False
            while (skipCheck or all(x <= 0 for x in count.values())) and start <= cur:
                if cur + 1 - start < bestEnd - bestStart:
                    bestStart, bestEnd = start, cur + 1
                if s[start] in count:
                    count[ord(s[start])] += 1
                    if count[ord(s[start])] <= 0:
                        skipCheck = True
                        start += 1
                    else:
                        skipCheck = False
                        start += 1
                        break
                else:
                    skipCheck = True
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