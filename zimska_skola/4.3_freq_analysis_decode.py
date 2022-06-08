import sys
import json
from collections import Counter


def generate_map(d):
    m = sorted(d.items(), key=lambda x: -x[1])
    m = [x[0] for x in m]

    normal_english = [('a', 0.08238488044272736), ('b', 0.016620315780269634), ('c', 0.025574059123696594), ('d', 0.04131553323468914), ('e', 0.11976377177366845), ('f', 0.018910482516123064), ('g', 0.021775790745273017), ('h', 0.057203445585672315), ('i', 0.06741443549968548), ('j', 0.0021912678665264255), ('k', 0.013484839609803637), ('l', 0.04116718493069863), ('m', 0.025167003262389312),
                      ('n', 0.06830431309429519), ('o', 0.0802243858295323), ('p', 0.018474775694817615), ('q', 0.0010066037279355773), ('r', 0.05668730384703868), ('s', 0.06305566945196443), ('t', 0.08802063038903335), ('u', 0.030911414627355003), ('v', 0.008762312484772545), ('w', 0.02361115001982222), ('x', 0.0017859098398857018), ('y', 0.02523512887838495), ('z', 0.0009473917439393669)]

    m2 = sorted(normal_english, key=lambda x: -x[1])
    m2 = [x[0] for x in m2]

    return dict(list(zip(m, m2)))


if __name__ == "__main__":
    d = Counter()

    with open("4_cypher_task2.txt") as f:
        for x in f:
            s = ''.join(ch for ch in x.lower() if 'a' <= ch <= 'z')

            d.update(s)

    # sm = sum(d.values())

    # print(",".join([f"{k}:{v/sm}" for k, v in d.items()]))

    m = generate_map(d)
    print(m)

    with open("4_cypher_task2.txt") as f:
        for line in f:
            s = ""
            for x in line.strip():
                if x in m:
                    s += m[x]
                else:
                    s += x

            print(s)
