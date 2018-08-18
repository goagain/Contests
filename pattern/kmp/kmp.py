class Solution:
    def getNext(self, needle):
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
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        next = self.getNext(needle)
        index = 0
        now = 0

        while True:
            if now == -1:
                now = 0
                index = index + 1
            if now == len(needle):
                return index-now
            if index == len(haystack):
                return -1
            if haystack[index] == needle[now]:
                index = index + 1
                now = now + 1
            else:
                now = next[now]
            

    
# print(Solution().strStr("aaaaa", "bba"))
# print(Solution().strStr("", ""))
# print(Solution().strStr("a", "a"))
# print(Solution().strStr("a", "b"))
print(Solution().getNext("aabaaac"))
print(Solution().strStr("aabaaabaaac", "aabaaac"))
