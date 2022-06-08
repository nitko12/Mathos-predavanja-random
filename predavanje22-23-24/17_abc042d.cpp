#include <iostream>
using namespace std;
typedef long long ll;

int h, w, a, b, f[200001], mod = 1e9 + 7;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int sub(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int &a, int b) { a = add(a, b); }
void subs(int &a, int b) { a = sub(a, b); }
void muls(int &a, int b) { a = mul(a, b); }
void maxs(int &a, int b) { a = max(a, b); }
void mins(int &a, int b) { a = min(a, b); }
int pwr(int a, ll p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

int bk(int h, int w)
{
    return mul(f[h + w - 2], inv(mul(f[h - 1], f[w - 1])));
}

int main()
{
    f[0] = 1;
    for (int i = 1; i < 200001; ++i)
        f[i] = mul(f[i - 1], i);
    cin >> h >> w >> a >> b;
    int sum = 0;
    for (int i = b + 1; i <= w; ++i)
        adds(sum, mul(bk(i, h - a), bk(w - i + 1, a)));
    cout << sum << endl;
    return 0;
}