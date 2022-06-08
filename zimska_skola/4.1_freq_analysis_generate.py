import json
from collections import Counter

if __name__ == "__main__":
    d = Counter()

    with open("4_dataset.json") as f:
        for x in json.load(f):
            s1 = ''.join(ch for ch in x["title"].lower() if 'a' <= ch <= 'z')
            s2 = ''.join(ch for ch in x["body"].lower() if 'a' <= ch <= 'z')

            d.update(s1)
            d.update(s2)

    sm = sum(d.values())

    print(",".join([f"{k}:{v/sm}" for k, v in d.items()]))
