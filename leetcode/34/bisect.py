import bisect


class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        index = bisect.bisect_left(nums, target)
        if index < 0 or index >= len(nums) or nums[index] != target:
            return [-1, -1]
        return [bisect.bisect_left(nums, target), bisect.bisect_right(nums, target)-1]


nums = [2, 2]
target = 6
print(Solution().searchRange(nums, target))

nums = [5, 7, 7, 8, 8, 10]
target = 8
print(Solution().searchRange(nums, target))

nums = [8]
target = 8
print(Solution().searchRange(nums, target))
