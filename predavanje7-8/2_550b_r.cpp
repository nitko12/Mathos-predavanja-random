#include <iostream>
using namespace std;

int n, l, r, x, a[50];

int f(int p, int val, int cnt, int mn, int mx)
{
    if (p == n &&
        cnt >= 2 &&
        mx - mn >= x &&
        l <= val && val <= r)
        return 1;

    if (p == n)
        return 0;

    return f(p + 1, val + a[p], cnt + 1, min(mn, a[p]), max(mx, a[p])) +
           f(p + 1, val, cnt, mn, mx);
}

int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << f(0, 0, 0, 1e9, -1e9) << endl;

    return 0;
}
