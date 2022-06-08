#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1 << 18; // 2.6e5
int N = 200000;
int seg[2 * MAXN]; // root is seg[1]

void update(int p, int val)
{
    for (seg[p += N] = val; p > 0; p >>= 1)
        seg[p >> 1] = seg[p] + seg[p ^ 1];
}

int query(int l, int r) // [l, r]
{
    if (l > r)
        return 0;
    int res = 0;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += seg[l++];
        if (!(r & 1))
            res += seg[r--];
    }
    return res;
}

int n, q, a[200005];
vector<int> b;
tuple<char, int, int> t[200005];
map<int, int> m;

int main()
{
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> a[i], b.push_back(a[i]);

    for (int i = 1; i <= n; ++i)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        t[i] = {c, x, y};

        if (c == '!')
            b.push_back(y);
    }

    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    // for (int i : b)
    //     cout << i << " ";
    // cout << endl;
    // cout << (upper_bound(b.begin(), b.end(), 5) - b.begin()) << endl;

    for (int i = 1; i <= n; ++i)
        a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();

    // for (int i = 1; i <= n; ++i)
    //     cout << a[i] << ", ";
    // cout << endl;

    for (int i = 1; i <= n; ++i)
    {
        m[i] = a[i];
        update(a[i], query(a[i], a[i]) + 1);
    }

    for (int i = 1; i <= q; ++i)
    {
        const auto [c, x, y] = t[i];

        // cout << c << " " << x << " " << y << endl;

        if (c == '?')
            t[i] = {c,
                    upper_bound(b.begin(), b.end(), x) - b.begin(),
                    upper_bound(b.begin(), b.end(), y) - b.begin()};
        else
            t[i] = {c,
                    x,
                    upper_bound(b.begin(), b.end(), y) - b.begin()};
    }

    // for (int i = 1; i <= q; ++i)
    // {
    //     const auto [c, x, y] = t[i];

    //     cout << c << " " << x << " " << y << endl;
    // }

    // for (int i = 1; i <= q; ++i)
    // {
    // }

    for (int i = 1; i <= q; ++i)
    {
        const auto [c, x, y] = t[i];

        // cout << c << " " << x << " " << y << endl;

        if (c == '?')
        {
            cout << query(x, y) << endl;
        }
        else
        {
            update(m[x], query(m[x], m[x]) - 1);
            m[x] = query(m[x], m[x]) - 1;
            update(y, query(y, y) + 1);
        }
    }

    return 0;
}
