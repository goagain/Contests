class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort()
        heaters.sort()
        ans = 0
        index = 0
        for x in houses:
            distance = abs(heaters[index] - x)
            while index + 1 < len(heaters) and heaters[index+1] < x:
                index += 1
                distance = min(distance, abs(heaters[index] - x))
            if index + 1 < len(heaters):
                distance = min(distance, abs(heaters[index + 1] - x))
            ans = max(ans, distance)
        return ans

print(Solution().findRadius([1,2,3],[2]))
print(Solution().findRadius([1,2,3,4],[1,4]))