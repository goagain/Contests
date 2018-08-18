import sys
import re
input()
s1 = input()
s2 = input()

def judge(s1, s2):
    if not '*' in s1:
        return s1 == s2
    else:
        if len(s1) > len(s2) + 1:
            return False
        s = str.split(s1, '*')
        return str.startswith(s2, s[0]) and str.endswith(s2, s[1])

print("YES" if judge(s1,s2) else "NO")