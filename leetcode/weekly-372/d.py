from typing import *
import math
class RMQ:
    def __init__(self, heights):
        depth = 16
        rmq = []
        self.heights = heights
        
        for k in range(depth):
            current = [0] * len(heights)
            rmq.append(current)
            for i in range(len(heights)):
                if k == 0:
                    current[i] = heights[i]
                else:
                    current[i] = max(rmq[k-1][i], rmq[k-1][min(i+(1<<(k-1)), len(heights)-1)])
        self.rmq = rmq
        print(rmq)
    def query_max(self, l:int, r:int) -> int:
        if l == r:
            return self.heights[l]
        k = int(math.log2(r - l + 1))
        return max(self.rmq[k][l], self.rmq[k][r-(1<<k)+1])
    
    def query(self, left: int, right: int) -> int:
        if left == right:
            return left
        
        if left > right:
            left, right = right, left
            
        if self.query_max(right, len(self.heights)-1) <= self.heights[left]:
            return -1
        
        l = right
        r = len(self.heights)-1
        
        while l < r:
            m = (l + r) // 2
            range_max = self.query_max(l, m)
            if range_max > self.heights[left]:
                r = m
            else:
                l = m + 1
        return l
        
class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        rmq = RMQ(heights)
        ans = []
        for q in queries:
            ans.append(rmq.query(q[0], q[1]))
        return ans
        
        
print(Solution().leftmostBuildingQueries([6,4,8,5,2,7],
[[0,1],[0,3],[2,4],[3,4],[2,2]]))

print(Solution().leftmostBuildingQueries([5,3,8,2,6,1,4,6],
[[0,7],[3,5],[5,2],[3,0],[1,6]]))

print(Solution().leftmostBuildingQueries([1,2,1,2,1,2],
[[0,0],[0,1],[0,2],[0,3],[0,4],[0,5],[1,0],[1,1],[1,2],[1,3],[1,4],[1,5],[2,0],[2,1],[2,2],[2,3],[2,4],[2,5],[3,0],[3,1],[3,2],[3,3],[3,4],[3,5],[4,0],[4,1],[4,2],[4,3],[4,4],[4,5],[5,0],[5,1],[5,2],[5,3],[5,4],[5,5]]))

[0, 1, 3, 3, 5, 5, 1, 1, -1, -1, -1, -1, 3, -1, 2, 3, 5, 5, 3, -1, 3, 3, -1, -1, 5, -1, 5, -1, 4, 5, 5, -1, 5, -1, 5, 5]
[0,1,3,3,5,5,1,1,-1,-1,-1,-1,3,-1,2,3,5,5,3,-1,3,3,-1,-1,5,-1,5,-1,4,5,5,-1,5,-1,5,5]