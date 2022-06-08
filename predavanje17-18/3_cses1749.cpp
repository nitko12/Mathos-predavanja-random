#include <iostream>
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

int n, a[200005];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        update(i, 1);

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;

        int lo = 1, hi = n + 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2; // pod
            if (query(1, mid) >= x)
                hi = mid;
            else
                lo = mid + 1;
        }

        cout << a[lo] << endl;
        update(lo, 0);

        // int idx = query(1, x);
        // cout << a[idx] << endl;
        // update(x, 0);
    }

    return 0;
}
