#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

typedef long long ll;

const int mod = 1e9 + 7;
int n, k, a[200005];

int sub(int a, int b) { return (a - b + mod) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

int fact[200005], finv[200005];

int ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return mul(fact[n], mul(finv[r], finv[n - r]));
}

signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    fact[0] = 1;
    for (int i = 1; i <= 200005; ++i)
        fact[i] = mul(fact[i - 1], i);

    for (int i = 0; i <= 200005; ++i)
        finv[i] = inv(fact[i]);

    // for (int i = 0; i < 100; ++i)
    //     cout << mul(fact[i], finv[i]) << endl;

    int mn = 0, mx = 0;

    sort(a, a + n);
    for (int i = k - 1; i < n; ++i)
        mx = add(mx, mul(a[i], ncr(i, k - 1)));

    reverse(a, a + n);
    for (int i = k - 1; i < n; ++i)
        mn = add(mn, mul(a[i], ncr(i, k - 1)));

    cout << sub(mx, mn) << endl;

    return 0;
}
