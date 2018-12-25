import sys
import math
import queue
input = queue.Queue()
for line in sys.stdin:
    [input.put(int(i)) for i in line.split()]
def C(n, m):
    return A(n) // A(m) // A(n-m)
def A(n):
    if n == 0:
        return 1
    return n * A(n-1)


while not input.empty():
    n, m, k = input.get(), input.get(), input.get()
    ans = C(n, k) * C(m, k) * A(k)
    print(ans)