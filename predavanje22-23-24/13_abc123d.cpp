#include <iostream>
using namespace std;

const int mod = 1000000007;
int n, a, b;

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int sub(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
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

int main()
{
    cin >> n >> a >> b;

    cout << sub(
                sub(pwr(2, n), 1), add(
                                       ncr(n, a), ncr(n, b)))
         << endl;

    return 0;
}
