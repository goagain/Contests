class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words:
            return []
        length = len(words[0])
        map = {}
        ans = []
        for subString in words:
            if subString in map:
                map[subString] = map[subString] + 1
            else:
                map[subString] = 1

        for i in range(length):
            m = map.copy()
            begin = i
            now = begin
            while now + length <= len(s):
                tmp = s[now: now + length]
                if not tmp in m:
                    m = map.copy()
                    begin = now + length
                    now = begin
                else:
                    if m[tmp] > 0:
                        m[tmp] = m[tmp] - 1
                        now = now + length
                        if not [True for x in m if m[x]]:
                            ans.append(begin)
                            m[s[begin: begin+length]] = m[s[begin: begin+length]] + 1
                            begin = begin + length
                    else:
                        while s[begin: begin+length] != tmp:
                            m[s[begin: begin+length]] = m[s[begin: begin+length]] + 1
                            begin = begin + length
                        m[s[begin: begin+length]] = m[s[begin: begin+length]] + 1
                        begin = begin + length

        return ans


print(Solution.findSubstring(None, "barfoothefoobarman", ["foo", "bar"]))
print(Solution.findSubstring(None, "wordgoodgoodgoodbestword", ["word","good","best","word"]))
