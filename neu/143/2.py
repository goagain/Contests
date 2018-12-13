import sys
import queue
input = queue.Queue()
for line in sys.stdin:
    [input.put(int(i)) for i in line.split()]
while not input.empty():
    x, y, r = input.get(), input.get(), input.get()
    x0, y0, x1, y1 = input.get(), input.get(), input.get(), input.get()
    A = y0 - y1
    B = x1 - x0
    C = x0 * y1 - x1 * y0
    if A == 0 and B == 0:
        print(0)
        continue
    d = (A*x + B*y + C)*(A*x + B*y + C) / (A*A+B*B)
    if d < r * r:
        print(2)
    elif d == r * r:
        print(1)
    else:
        print(0)