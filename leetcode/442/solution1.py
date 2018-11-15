import math
class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for a in nums:
            index = a if a > 0 else -a
            if nums[index-1] < 0:
                ans.append(index)
            nums[index-1] *= -1
        return ans

print(Solution().findDuplicates([4,3,2,7,8,2,3,1]))