import sys

for line in sys.stdin:
    a, b, c = [int(x) for x in line.split()]
    print(pow(a, pow(b, c, int(1e9+6)), int(1e9+7)))