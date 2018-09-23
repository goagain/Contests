n = input()
a = [int(x) for x in input().split()]
if any(a):
    print("HARD")
else:
    print("EASY")