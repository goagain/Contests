def getNext(needle):
    if len(needle) == 0:
        return [-1]
    next = [0] *(len(needle)+1)
    next[0] = -1
    next[1] = 0

    now = 0
    for i in range(1, len(needle)):
        while needle[i] != needle[now] and now > 0:
            now = next[now]
        if needle[i] == needle[now]:
            now = now + 1
        next[i+1] = now
    return next

class Solution:
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        next = getNext(s)
        if next[-1] != 0 and len(s) % (len(s)-next[-1]) == 0:
            return True
        return False

print(Solution().repeatedSubstringPattern("abac"))
print(Solution().repeatedSubstringPattern(""))
print(Solution().repeatedSubstringPattern("abcabcabcabc"))
print(Solution().repeatedSubstringPattern("abab"))
print(Solution().repeatedSubstringPattern("aba"))