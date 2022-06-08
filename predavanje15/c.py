from functools import cache

n = 0
a, b, c = [0 for _ in range(100005)], [0 for _ in range(100005)], [
    0 for _ in range(100005)]


@cache
def f(p, l):
    if p == n:
        return 0

    mn = -1e9
    if l == 0:
        mn = max(mn, b[p] + f(p + 1, 1))
        mn = max(mn, c[p] + f(p + 1, 2))
    elif l == 1:
        mn = max(mn, a[p] + f(p + 1, 0))
        mn = max(mn, c[p] + f(p + 1, 2))
    elif l == 2:
        mn = max(mn, a[p] + f(p + 1, 0))
        mn = max(mn, b[p] + f(p + 1, 1))
    else:
        mn = max(mn, a[p] + f(p + 1, 0))
        mn = max(mn, b[p] + f(p + 1, 1))
        mn = max(mn, c[p] + f(p + 1, 2))

    return mn


if __name__ == "__main__":
    n = int(input())
    for x in range(n):
        a[x], b[x], c[x] = map(int, input().split())
    print(f(0, -1))
