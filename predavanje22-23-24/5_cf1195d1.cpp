#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int n, a[100000];
ll b1[100000], b2[100000], mod = 998244353;
ll p10[20];

ll add(ll a, ll b) { return (a += b) < mod ? a : a - mod; }
ll sub(ll a, ll b) { return (a -= b) >= 0 ? a : a + mod; }
ll mul(ll a, ll b) { return 1LL * a * b % mod; }
void adds(ll &a, ll b) { a = add(a, b); }
void subs(ll &a, ll b) { a = sub(a, b); }
void muls(ll &a, ll b) { a = mul(a, b); }
void maxs(ll &a, ll b) { a = max(a, b); }
void mins(ll &a, ll b) { a = min(a, b); }

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    p10[0] = 1;
    for (int i = 1; i < 20; ++i)
        p10[i] = p10[i - 1] * 10ll;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 10; ++j)
            adds(b1[i], mul(((a[i] / p10[j]) % 10), p10[j * 2]));

    ll sum = 0;
    for (int i = 0; i < n; ++i)
        adds(sum, mul(add(mul(b1[i], 10ll), b1[i]), n));

    cout << sum << endl;
    return 0;
}