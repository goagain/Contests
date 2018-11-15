import math
class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        nums = [n - 1 for n in nums]
        for i in range(len(nums)):
            if nums[i] == i:
                continue
            index = i
            while nums[index] != index and nums[index] != -1:
                t = nums[index]
                nums[index], nums[t] = nums[t], nums[index]
                if nums[index] == nums[t]:
                    ans.append(nums[index] + 1)
                    nums[index] = -1
                    break
        return ans

print(Solution().findDuplicates([4,3,2,7,8,2,3,1]))