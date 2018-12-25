import sys

n = int(input())
for line in sys.stdin:
    if not line:
        continue
    if line[-1] == '\n':
        line = line[:-1]
    lastChar = line[-1]
    if str.isalpha(lastChar):
        if line.lower() == "you lose":
            print("Bling!")
        else:
            print(line+"?")
    else:
        if line[:-1].lower() == "you lose":
            print("Bling!")
        else:
            print(line[:-1]+"?")
