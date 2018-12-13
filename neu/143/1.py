import sys

isPrime = [True for i in range(1000001)]
prime = []
for i in range(2, 1000000):
    if isPrime[i]:
        prime.append(i)
        for j in range(1, 1000000//i + 1):
            isPrime[j*i] = False

for line in sys.stdin:
    n = int(line)
    print(' '.join([str(x) for x in prime if x <= n]))