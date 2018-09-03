import math
import queue
n = int(input())
a = [int(c) for c in input().split()]

flag = True

lcm = a[0]
q = queue.Queue()
for i in range(1, n):
    q.put(a[i])

count = 0
while not q.empty() and count < n:
    top = q.get()
    if math.gcd(top, lcm) > 1:
        lcm = top * lcm // math.gcd(top, lcm)
        count = 0
    else:
        q.put(top)
        count = count + 1
if q.empty():
    print(lcm)
    print("Yes")
else:
    print("No")