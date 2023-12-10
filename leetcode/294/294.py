from functools import cache

@cache
def sg(n: int) -> int:
    if n == 0 or n == 1:
        return 0
    nexts = set()
    for x in range(n-1):
        nexts.add(sg(x) ^ sg(n-2-x))

    for i in range(n):
        if i not in nexts:
            return i
    return n

class Solution:
    def canWin(self, s: str) -> bool:
        cnt = 0
        state = 0

        for c in s:
            if c == '+':
                cnt += 1
            else:
                state ^= sg(cnt)
                cnt = 0
        state ^= sg(cnt)
        
        return state > 0
    
print(Solution().canWin("++++"))
print(Solution().canWin("++"))
print(Solution().canWin("+++"))
print(Solution().canWin("+++-+++"))
print(Solution().canWin("+++++"))