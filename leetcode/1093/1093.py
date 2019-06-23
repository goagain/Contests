import math
class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        for i in range(256):
            if count[i]:
                minimum = i
                break
        for i in range(255, -1, -1):
            if count[i]:
                maximum = i
                break
        sum = 0
        square_sum = 0
        total_count = 0
        mode = 0
        mode_index = 0
        for i in range(256):
            sum += i * count[i]
            square_sum += i * i * count[i]
            total_count += count[i]
            if count[i] > count[mode_index]:
                mode_index = i
        mean = sum / total_count
        mode = mode_index

        if total_count % 2 == 0:
            less_index = total_count // 2
            bigger_index = less_index + 1
            less = 0
            bigger = 0
            for i in range(256):
                if count[i] > 0:
                    if less_index <= count[i]:
                        less = i
                        break
                    less_index -= count[i]
            for i in range(256):
                if count[i] > 0:
                    if bigger_index <= count[i]:
                        bigger = i
                        break
                    bigger_index -= count[i]
            median = (less + bigger) / 2
        else:
            index = total_count // 2
            for i in range(256):
                if count[i] > 0:
                    if index <= count[i]:
                        median = i
                        break
                    index -= count[i]

        return [float(minimum), float(maximum), float(mean), float(median), float(mode)]