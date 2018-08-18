import math
t = input().split()
n, q = int(t[0]), int(t[1])
a = [int(s) for s in input().split()]
rawA = a.copy()
hasZero = False
allAreZero = True
lastNonZero = 1
firstZero = 0
for i in range(n):
    if a[i] != 0:
        if allAreZero:
            for j in range(i):
                a[j] = a[i]
        lastNonZero = a[i]
        allAreZero = False
    else:
        hasZero = True
        firstZero = i
        if not allAreZero:
            a[i] = lastNonZero
if allAreZero:
    a = [q] * n
    print("YES")
    print(" ".join([str(c) for c in a]))
    exit()

rmq = []
rmq.append(a)
for k in range(1, int(math.log(n, 2) + 1)):
    t = rmq[k-1]
    x = []
    for i in range(n):
        r = min(i + pow(2, k - 1), n - 1)
        x.append(min(t[i], t[r]))
    rmq.append(x)

def query(ll, rr):
    if ll > rr:
        return q + 1
    k = int(math.log(rr - ll + 1, 2))
    return min(rmq[k][ll], rmq[k][rr - pow(2, k) + 1])

l = {}
r = {}
for i in range(n):
    if not a[i] in l:
        l[a[i]] = i
    r[a[i]] = i

for x in range(1, q + 1):
    if x in l:
        if query(l[x]+1, r[x]-1) < x:
            print("NO")
            exit()

if not q in l:
    if not hasZero:
        print("NO")
        exit()
    else:
        a[firstZero] = q

print("YES")
for c in a:
    print(c, end = ' ')