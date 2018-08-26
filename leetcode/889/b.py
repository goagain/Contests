class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        ans = []
        for word in words:
            m = {}
            rm = {}
            for index in range(len(word)):
                c = word[index]
                flag = True
                if c in m:
                    if m[c] != pattern[index]:
                        flag = False
                        break
                else:
                    if pattern[index] in rm and rm[pattern[index]] != c:
                        flag = False
                        break
                    m[c] = pattern[index]
                    rm[pattern[index]] = c
            if flag:      
                ans.append(word)
        return ans
print(Solution().findAndReplacePattern(["abc","deq","mee","aqq","dkd","ccc"], "abb"))