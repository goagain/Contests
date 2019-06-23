# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        highest_index = 0
        l = 0
        r = mountain_arr.length()
        while l < r:
            m = (l + r) // 2
            m2 = (m + r) // 2
            if mountain_arr.get(m) < mountain_arr.get(m2):
                l = m + 1
                higher = m2
            else:
                r = m2
                higher = m
            if r - l <= 1:
                break
        highest_index = higher
        print(highest_index)
        # find target in left
        l = 0
        r = highest_index
        while l < r:
            m = (l + r) // 2
            value = mountain_arr.get(m)
            if value < target:
                l = m + 1
            elif value > target:
                r = m
            else:
                return m
        if l < mountain_arr.length() and mountain_arr.get(l) == target:
            return l
        # find target in right
        l = highest_index
        r = mountain_arr.length()
        while l < r:
            m = (l + r) // 2
            value = mountain_arr.get(m)
            if value > target:
                l = m + 1
            elif value < target:
                r = m
            else:
                return m
        if l < mountain_arr.length() and mountain_arr.get(l) == target:
            return l
        return -1