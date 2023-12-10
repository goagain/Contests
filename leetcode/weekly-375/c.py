from collections import Counter, defaultdict
from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        length = len(nums)
        total = length * (length+1) // 2        
        maximum = max(nums)
        
        ans = 0
        counts = 0
        last = 0
        
        for i in range(len(nums)):
            if nums[i] == maximum:
                counts += 1
            while counts >= k:
                if nums[last] == maximum:
                    counts -= 1
                last += 1
            # print(last, i)
            ans += i - last + 1

        # print(ans)
        return total - ans

    def verify(self, nums: List[int], k: int):
        ans = 0
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if max(Counter(nums[i:j+1]).values()) >= k:
                    ans += 1
                    print(i, j)
        return ans
print(Solution().countSubarrays([61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82],2))
# print(Solution().verify([61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82],2))
# print(Solution().countSubarrays([2, 1,1,1,1,1],2))