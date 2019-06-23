class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        sort_by_start = sorted(trips, key = lambda x : x[1])
        sort_by_target = sorted(trips, key = lambda x : x[2])

        index_of_sort_by_target = 0
        for trip in sort_by_start:
            capacity -= trip[0]
            while index_of_sort_by_target < len(sort_by_target) and sort_by_target[index_of_sort_by_target][2] <= trip[1]:
                capacity += sort_by_target[index_of_sort_by_target][0]
                index_of_sort_by_target += 1
            if capacity < 0:
                return False

        return True

print(Solution().carPooling([[2, 1, 5], [3, 3, 7]], 4))
print(Solution().carPooling([[2, 1, 5], [3, 3, 7]], 5))
print(Solution().carPooling([[2, 1, 5], [3, 5, 7]], 3))
print(Solution().carPooling([[3,2,7],[3,7,9],[8,3,9]], 11))