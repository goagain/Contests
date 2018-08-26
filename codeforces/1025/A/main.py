n = int(input())
s = input()

if len(s) == 1:
    print("Yes")
    exit()
m = {}
for i in s:
    if i in m:
        print("Yes")
        exit()
    else:
        m[i] = 1

print("No")