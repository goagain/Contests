class Solution:
    def subsets(self, nums):
        sets = []
        for i in range(2 ** len(nums)):
            sets.append([nums[bit] for bit in range(len(nums)) if (1 << bit) & i > 0])
        return sets
