k = int(input())
for x in range(1, k + 1):
    print((((x ** 2 - 9) * (x - 4) ** 2) + ((x ** 2 - 5) * 4 * (x - 4)) + ((x ** 2 - 7)
                                                                           * 4 * (x - 4)) + ((x ** 2 - 5) * 4) + ((x ** 2 - 4) * 8) + ((x ** 2 - 3) * 4)) // 2)
