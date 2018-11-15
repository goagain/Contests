class Solution:
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        a = []
        count0 = 0
        for c in S:
            if c == '0':
                count0 += 1
            a.append(count0)
        ans = len(S)
        for i in range(len(S)+1):
            temp = 0
            cur = 0
            if i > 0:
                cur = a[i-1]
                temp = i - a[i-1]
            if i < len(S):
                temp += a[len(S)-1] - cur
            ans = min(ans, temp)
        return ans