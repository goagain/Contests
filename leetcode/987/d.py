from functools import total_ordering

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

@total_ordering
class Point:
    def __init__(self, x, y, val):
        self.val = val
        self.x = x
        self.y = y
    def __eq__(self, other):
        return self.val == other.val and self.x == other.x and self.y == other.y
    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        if self.y != other.y:
            return self.y > other.y
        return self.val < other.val
    def __str__(self):
        return "y : {0} x : {1} val : {2}".format(self.y, self.x, self.val)
class Solution:
    points = []
    def verticalTraversal(self, root: 'TreeNode') -> 'List[List[int]]':
        self.points = []
        self.process(root, 0, 0)
        self.points = sorted(self.points)
        print([str(x) for x in self.points])
        ans = []
        lastX = None
        cur = []
        for x in self.points:
            if x.x == lastX:
                cur.append(x.val)
            else:
                if cur:
                    ans.append(cur)
                cur = [x.val]
                lastX = x.x
        if cur:
            ans.append(cur)
        return ans
            
    def process(self, root, x, y):
        if root == None:
            return
        self.points.append(Point(x, y, root.val))
        self.process(root.left, x - 1, y - 1)
        self.process(root.right, x + 1, y - 1)
