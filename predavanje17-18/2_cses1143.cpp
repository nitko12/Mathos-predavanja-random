#include <iostream>
using namespace std;

const int MAXN = 1 << 18; // 2.6e5
int N = 200000;
int seg[2 * MAXN]; // root is seg[1]

void update(int p, int val)
{
    for (seg[p += N] = val; p > 0; p >>= 1)
        seg[p >> 1] = max(seg[p], seg[p ^ 1]);
}

int query(int l, int r) // [l, r]
{
    int res = 0;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, seg[l++]);
        if (!(r & 1))
            res = max(res, seg[r--]);
    }
    return res;
}

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        update(i, x);
    }

    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;

        // for (int i = 0; i < n; ++i)
        // {
        //     cout << (query(1, i) >= x);
        // }
        // cout << endl;

        int lo = 1, hi = n + 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2; // pod
            if (query(1, mid) >= x)
                hi = mid;
            else
                lo = mid + 1;
        }

        // cout << lo << endl;

        if (lo == n + 1)
            cout << 0 << endl;
        else
        {
            cout << lo << endl;
            update(lo, query(lo, lo) - x);
        }

        // cout << query(1, 2) << endl;
    }

    return 0;
}