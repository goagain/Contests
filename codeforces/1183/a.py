n = int(input())
while sum([int(x) for x in str(n)]) % 4 != 0:
    n += 1

print (n)