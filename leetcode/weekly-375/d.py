from typing import List


class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        stack = []
        
        appears = {}
        
        for i in range(len(nums)):
            if nums[i] in appears:
                while stack and appears[nums[i]] <= stack[-1][1]:
                    stack.pop()
                if stack:
                    stack.append((stack[-1][1], i))
                else:
                    stack.append((0, i))
            else:
                appears[nums[i]] = i
                stack.append([i, i])
                
        print(stack, len(stack))
        
        return pow(2, len(stack) -1, 10**9+7)
    
print(Solution().numberOfGoodPartitions([1,5,1,5,6]))
print(Solution().numberOfGoodPartitions([1,2,1,3]))