import sys
import queue
try:
    input = queue.Queue()
    for line in sys.stdin:
        [input.put(int(i)) for i in line.split()]
    while not input.empty():
    # for n in sys.stdin:
        n = input.get()
        a = [input.get() for x in range(n)]
        allsum = sum(a)
        tsum = 0
        for index, x in enumerate(a):
            tsum += x
            if tsum * 2 >= allsum:
                print(index + 1) 
                break
except:
    pass