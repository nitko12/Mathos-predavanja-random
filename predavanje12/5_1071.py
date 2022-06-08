t = int(input())
for i in range(t):
    y, x = map(int, input().split())
    if x == 1 and y == 1:
        print("1")
    else:
        rj = 0
        if x <= y:
            rj += (y - 1) * (y - 1)
            sm = (y - 1) * 2 + 1
            if y & 1:
                rj += x
            else:
                rj += sm - x + 1
        else:
            # x 5 y 2 = 24
            rj += (x - 1) * (x - 1)
            sm = (x - 1) * 2 + 1
            if x & 1:
                rj += sm - y + 1
            else:
                rj += y
        print(rj)
