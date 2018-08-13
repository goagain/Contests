class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 0
        for n in nums:
            if index == 0 or nums[index-1] != n:
                nums[index] = n
                index = index + 1
        del nums[index:]
        return index


print(Solution().removeDuplicates([1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 6]))
print(Solution().removeDuplicates([1, 1, 2]))
print(Solution().removeDuplicates([]))
