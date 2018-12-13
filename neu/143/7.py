try:
    while True:
        line = [float(s) for s in input().split()]
        radius, heigth, width = line[0], line[1], line[2]
        print("Alice" if radius * 2 <= heigth and radius * 2 <= width else "Bob")
except EOFError:
    pass