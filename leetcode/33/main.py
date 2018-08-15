class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums: return -1
        l, r = 0, len(nums)
        while l < r:
            m = (l + r) // 2
            if nums[m] > nums[-1]:
                l = m + 1
            else:
                r = m
        # print(l)
        ll = l
        rr = l + len(nums)
        while ll < rr:
            m = (ll + rr) // 2
            if nums[m % len(nums)] < target:
                ll = m + 1
            else:
                rr = m

        return ll % len(nums) if nums[ll % len(nums)] == target else -1

print(Solution().search([5, 1, 3], 1))

print(Solution().search([4, 5, 6, 7, 0, 1, 2], 3))
print(Solution().search([1, 2, 3, 4, 5, 6, 7], 3))
print(Solution().search([8, 1, 2, 3, 4, 5, 6, 7], 3))
print(Solution().search([3, 1], 1))
print(Solution().search([4, 5, 6, 7, 8, 1, 2, 3], 8))
