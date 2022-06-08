#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, t, a[200000];

bool f(ll x)
{
    ll f = 0;
    for (int i = 0; i < n; ++i)
        f += x / a[i];
    if (f < 0)
        return 1;
    return f >= t;
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll lo = 1, hi = 1000000000000000000;
    while (lo < hi)
    {
        ll md = (lo + hi) / 2;
        if (f(md))
            hi = md;
        else
            lo = md + 1;
    }
    cout << lo << endl;

    return 0;
}
