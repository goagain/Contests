class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        answer = []
        a = 0
        b = 0
        for c in seq:
            if c == '(':
                if a <= b:
                    a += 1
                    answer.append(0)
                else:
                    b += 1
                    answer.append(1)
            else:
                if a > b:
                    a -= 1
                    answer.append(0)
                else:
                    b -= 1
                    answer.append(1)
        return answer