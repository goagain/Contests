s = input()

ans = 1
m = [1] * len(s)
for i in range(1, len(s)):
    if s[i] != s[i-1]:
        m[i] = m[i-1] + 1
        if m[i] > ans:
            ans = m[i]
    else:
        m[i] = 1

if s[0] != s[-1]:
    if m[-1] == len(s):
        print(m[-1])
        exit()
    else:
        for i in range(len(s)):
            if s[i] != s[i-1]:
                m[i] = m[i-1]+1
                if m[i] > ans:
                    ans = m[i]
            else:
                break
        print(ans)
        exit()
else:
    print(ans)
