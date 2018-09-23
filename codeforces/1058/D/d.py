import math

line = input().split()
n = int(line[0])
m = int(line[1])
k = int(line[2])


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, (a % b))


target = n * m * 2 // k
if n * m * 2 % k or k < 2:
    print("NO")
else:
    target = int(target)
    
    exgcd = gcd(target, n)
    if exgcd <= n and target // exgcd <= m:
        width = exgcd
        height = target // width
        print('YES')
        print(0, 0)
        print(width, 0)
        print(0, height)
    else:
        exgcd = gcd(target, m)
        if exgcd <= m and target // exgcd <= n:
            height = exgcd
            width = target // height
            print('YES')
            print(0, 0)
            print(width, 0)
            print(0, height)
        else:
            print("NO")