import sys

n = int(input())
for line in sys.stdin:
    if not line:
        continue
    menu = line.split()
    hasChives = "Chives" in menu
    hasVegetable = "Vegetable" in menu
    hasEgg = "Egg" in menu

    if hasChives and not hasVegetable:
        print("Chives")
    elif hasChives and hasVegetable:
        print("Mixed")
    elif hasVegetable and hasEgg:
        print("Mixed")
    else:
        print("Vegetable")