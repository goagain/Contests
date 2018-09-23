n = int(input())
s = input()
a = [int(c) for c in s]

def dfs(Sum, start):
    if start == len(s):
        return True
    for i in range(start + 1, len(s)+1):
        if sum(a[start:i]) > Sum:
            break
        if sum(a[start:i]) == Sum:
            if dfs(Sum, i):
                return True
    return False

for i in range(1, len(s)):
    firstSum = sum(a[:i])
    if dfs(firstSum, i):
        print("YES")
        break
else:
    print("NO")