import math
n = int(input())
p = []
for i in range(n):
    t = input().split()
    a, b = int(t[0]), int(t[1])
    p.append((a,b))

gcd = 0
for (a, b) in p:
    lcm = a * b // math.gcd(a, b)
    if gcd == 0:
        gcd = lcm
    gcd = math.gcd(lcm, gcd)

if gcd == 1:
    print(-1)
    exit()
else:
    for i in range(2, int(math.sqrt(gcd) + 1)):
        if gcd % i == 0:
            print(i)
            exit()
print(gcd)