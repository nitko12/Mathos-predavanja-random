import sys

if __name__ == "__main__":
    m = {}

    for x in range(26):
        l = input().split()
        m[l[0]] = l[2]

    for line in sys.stdin:
        s = ""
        for c in line.strip().lower():
            if c in m:
                s += m[c]
            else:
                s += c

        print(s)
