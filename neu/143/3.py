import queue
import sys

input = queue.Queue()
for line in sys.stdin:
    [input.put(i) for i in line.split()]

while not input.empty():
    n = int(input.get())
    q = queue.Queue()
    st = []
    ans = 0
    for _ in range(n):
        handle, value = int(input.get()), input.get()
        if handle == 1:
            st.append(value)
            q.put(value)
        else:
            if q.get() != value:
                ans = 1
            if st.pop() != value:
                ans = 2
    if ans == 0:
        print("Not Sure")
    if ans == 1:
        print("Stack")
    if ans == 2:
        print("Queue")
