#include <iostream>
using namespace std;

#define int long long

int x, y;
const int mod = 1000000007;

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

int ncr(int n, int r)
{
    int res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = mul(res, n - i + 1);
        res = mul(res, inv(i));
    }
    return res;
}

signed main()
{
    cin >> x >> y;

    if (
        (2ll * x - y) % 3ll != 0 ||
        (2ll * y - x) % 3ll != 0)
        return cout << 0, 0;

    int a = (2ll * y - x) / 3ll;
    int b = (2ll * x - y) / 3ll;

    if (a < 0 || b < 0)
        return cout << 0, 0;

    // cout << a << " " << b << endl;

    cout << ncr(a + b, a) << endl;

    return 0;
}
