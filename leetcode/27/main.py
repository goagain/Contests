class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        index = 0
        for n in (nums):
            if val != n:
                nums[index] = n
                index = index + 1
        return index


print(Solution().removeElement([1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 6], 3))
print(Solution().removeElement([1, 1, 2], 1))
print(Solution().removeElement([], 1))
