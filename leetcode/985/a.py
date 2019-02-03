class Solution:
    def sumEvenAfterQueries(self, A: 'List[int]', queries: 'List[List[int]]') -> 'List[int]':
        evenSum = sum([x for x in A if x % 2 == 0])
        ans = []
        for query in queries:
            val = query[0]
            index = query[1]
            raw = A[index]
            A[index] += val
            new = A[index]
            if raw % 2 == 0:
                if new % 2 == 0:
                    evenSum += new - raw
                else:
                    evenSum -= raw
            else:
                if new % 2 == 0:
                    evenSum += new
            ans.append(evenSum)
        return ans
