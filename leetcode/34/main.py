class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(nums)
        while l < r:
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m
        if l >= len(nums) or nums[l] != target:
            return [-1, -1]
        l1 = l
        r = len(nums)
        while l < r:
            m = (l + r) // 2
            if nums[m] <= target:
                l = m + 1
            else:
                r = m
        return [l1, l - 1]


nums = [5, 7, 7, 8, 8, 10]
target = 6
print(Solution().searchRange(nums, target))

nums = [5, 7, 7, 8, 8, 10]
target = 8
print(Solution().searchRange(nums, target))

nums = [8]
target = 8
print(Solution().searchRange(nums, target))
