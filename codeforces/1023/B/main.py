s = input().split()
a, b = int(s[0]), int(s[1])

ll = b - 1
ls = 2
if ll > a:
    ll = a
if ls * 2 <= b:
    ls = b // 2 + 1

res = ll - ls + 1

print(res if res > 0 else 0)