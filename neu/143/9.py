import math
import sys
import queue

def joesphus(x):
    if x == 1:
        return 0
    if x == 2:
        return 1
    mod = x % 3
    n = joesphus(x - x//3)
    if n < mod:
        return x - mod + n
    return (n-mod) // 2 *3 + (n-mod) % 2

input = []
for line in sys.stdin:
    [input.append(int(i)) for i in line.split()]

for n in input:
    print(joesphus(n)+ 1)
