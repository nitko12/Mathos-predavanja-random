def generate_cn(c, n):
    if n == 0:
        return set(c)
    else:
        # create a set to hold our new elements
        cn = set()

        # generate c_(n-1)
        cn_minus_1 = generate_cn(c, n-1)

        for u in c:
            for v in cn_minus_1:
                if (len(u) > len(v)) and u.find(v) == 0:
                    cn.add(u[len(v):])
        for u in cn_minus_1:
            for v in c:
                if len(u) > len(v) and u.find(v) == 0:
                    cn.add(u[len(v):])
        return cn


def generate_c_infinity(c):
    cs = []
    c_infinity = set()
    n = 1
    cn = generate_cn(c, n)
    print('c_{}'.format(n), cn)

    return cn


def sardinas_patterson_theorem(c):
    """
    Returns True if c is uniquely decodable
    """
    c_infinity = generate_c_infinity(c)
    return len(c.intersection(c_infinity)) == 0


def check_decodability(c):
    if sardinas_patterson_theorem(c):
        print(c, 'is uniquely decodable')
    else:
        print(c, 'is not uniquely decodable')


c = set(["0", "01", "10", "11"])


check_decodability(c)
