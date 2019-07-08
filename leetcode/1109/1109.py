from typing import *
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        answer = [0] * n
        diff = [0] * (n + 1)
        for order in bookings:
            diff[order[0] - 1] += order[2]
            diff[order[1]] -= order[2]
        answer[0] = diff[0]
        for i in range(1, n):
            answer[i] = answer[i-1] + diff[i]

        return answer
