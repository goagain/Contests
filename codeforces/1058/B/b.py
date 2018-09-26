import math
line = input().split()
n = int(line[0])
d = int(line[1])

rect = [(0, d), (d, 0), (n, n-d), (n-d, n), (0, d)]


def dis(v):
    return math.sqrt(v[0]*v[0] + v[1]*v[1])


def dot(v1, v2):
    return v1[0]*v2[0] + v1[1]*v2[1]


def minus(v1, v2):
    return (v1[0]-v2[0], v1[1] - v2[1])


def cross(v1, v2):
    return v1[0]*v2[1] - v1[1]*v2[0]


def whetherInRect(x, y):
    p = (x, y)
    for i in range(1, 5):
        a = minus(p, rect[i])
        b = minus(p, rect[i-1])
        # print(cross(a, b))
        if cross(a, b) > 0:
            return False
    return True


t = int(input())
while t:
    t -= 1
    line = input().split()
    x = int(line[0])
    y = int(line[1])
    print("YES" if whetherInRect(x, y) else "NO")
