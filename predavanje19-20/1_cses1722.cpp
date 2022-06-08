#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef array<array<ll, 2>, 2> mat22;
typedef array<array<ll, 1>, 2> mat12;

ll n, mod = 1e9 + 7;

mat22 mul(mat22 a, mat22 b)
{
    mat22 t = {0, 0, 0, 0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                t[i][j] = (t[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
    return t;
}

mat22 exp(mat22 m, ll p)
{
    if (p == 0)
        return mat22{
            1,
            0,
            0,
            1,
        };
    if (p == 1)
        return m;

    if (p % 2 == 0)
        return exp(mul(m, m), p / 2);
    else
        return mul(m, exp(m, p - 1));
}

int main()
{
    cin >> n;
    --n;
    if (n == -1)
        return cout << 0 << endl, 0;
    if (n == 0)
        return cout << 1 << endl, 0;
    mat22 res = exp({0, 1,
                     1, 1},
                    n);
    mat12 r = {
              0,
              1,
          },
          rj = {0, 0};

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 1; ++j)
            for (int k = 0; k < 2; ++k)
                rj[i][j] = (rj[i][j] + 1ll * res[i][k] * r[k][j]) % mod;

    cout << rj[1][0] << endl;
    return 0;
}