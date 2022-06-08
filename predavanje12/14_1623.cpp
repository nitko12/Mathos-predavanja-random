#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, a[200005];

signed main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int mn = 1e9;
    for (int i = 0; i < (1 << n); ++i)
    {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < n; ++j)
            ((i & (1 << j)) ? s1 : s2) += a[j];

        mn = min(mn, abs(s1 - s2));
    }

    cout << mn << endl;

    return 0;
}