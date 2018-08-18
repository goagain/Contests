i = input().split()
n, k = int(i[0]), int(i[1])
s = input()

k = k // 2
left = 0
stackSize = 0

ans = []
for c in s:
    if c == '(' and left < k:
        ans.append(c)
        left = left + 1
        stackSize = stackSize + 1
    elif c == ')' and stackSize > 0:
        ans.append(c)
        stackSize = stackSize - 1

print("".join(ans))
