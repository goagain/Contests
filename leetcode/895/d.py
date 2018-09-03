import queue
import collections
class FreqStack:
    m = collections.defaultdict(int)
    pq = queue.PriorityQueue()
    index = 0
    def __init__(self):
        self.m = collections.defaultdict(int)
        self.pq = queue.PriorityQueue()
        self.index = 0
        return
    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.m[x] += 1
        self.index += 1
        self.pq.put( (-self.m[x], -self.index, x) )

    def pop(self):
        """
        :rtype: int
        """
        top = self.pq.get()
        self.m[top[2]] -= 1
        return top[2]


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()