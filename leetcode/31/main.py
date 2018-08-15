class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-2, -1, -1):
            if nums[i] < nums[i+1]:
                for j in range(len(nums)-1, -1, -1):
                    if nums[j] > nums[i]:
                        nums[i], nums[j] = nums[j], nums[i]
                        nums[i+1:] = list(reversed(nums[i+1:]))
                        return nums
        nums.reverse()
        return nums

assert(Solution().nextPermutation([1, 3, 2]) == [2, 1, 3])
assert(Solution().nextPermutation([3, 2, 1]) == [1, 2, 3])
assert(Solution().nextPermutation([1, 1, 5]) == [1, 5, 1])
assert(Solution().nextPermutation([2, 3, 1]) == [3, 1, 2])
assert(Solution().nextPermutation([1, 2, 3]) == [1, 3, 2])