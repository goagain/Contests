import math

line = input().split()
n = int(line[0])
m = int(line[1])
k = int(line[2])


def gcd(a, b):
    if b == 0:
        return int(a)
    else:
        return gcd(b, int(a % b))


target = n * m * 2 / k
if int(target) != target or k < 2:
    print("NO")
else:
    target = int(target)
    
    gcd = math.gcd(target, n)
    if gcd <= n and target // gcd <= m:
        width = gcd
        height = target // width
        print('YES')
        print(0, 0)
        print(width, 0)
        print(0, height)
    else:
        gcd = math.gcd(target, m)

        height = gcd
        width = target // height
        print('YES')
        print(0, 0)
        print(width, 0)
        print(0, height)
