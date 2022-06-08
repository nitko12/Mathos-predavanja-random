#include <iostream>
using namespace std;

int n, l, r, x, a[50];

int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int rj = 0;
    for (int i = 0; i < (1 << n); ++i)
    {
        int cnt = 0, sum = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                ++cnt, sum += a[j];

        // cout << sum << endl;

        if (cnt < 2 || !(l <= sum && sum <= r))
            continue;

        int mn = 1e9, mx = -1e9;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                mn = min(mn, a[j]), mx = max(mx, a[j]);

        if (mx - mn < x)
            continue;

        ++rj;
    }

    cout << rj << endl;

    return 0;
}
