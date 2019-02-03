# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    def intervalIntersection(self, A: 'List[Interval]', B: 'List[Interval]') -> 'List[Interval]':
        ans = []
        indexA = 0
        indexB = 0
        while indexA < len(A) and indexB < len(B):
            a = A[indexA]
            b = B[indexB]
            if a.start <= b.start:
                if b.start <= a.end:
                    if b.end <= a.end:
                        ans.append(Interval(b.start, b.end))
                        indexB += 1
                    else:
                        ans.append(Interval(b.start, a.end))
                        indexA += 1
                else:
                    indexA += 1
            else:
                if a.start <= b.end:
                    if a.end <= b.end:
                        ans.append(Interval(a.start, a.end))
                        indexA += 1
                    else:
                        ans.append(Interval(a.start, b.end))
                        indexB += 1
                else:
                    indexB += 1
        return ans
