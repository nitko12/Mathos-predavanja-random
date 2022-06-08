#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <numeric>
using namespace std;

typedef long long ll;

int maxn = 1000005;

ll n = 1000000000000,
   k = 1000000;

bool noPrime[1000005];
ll a[1000005], b[1000005];

int main()
{
    cin >> n >> k;
    noPrime[0] = noPrime[1] = 1;
    for (int i = 2; i <= maxn; ++i)
        for (int j = 2 * i; j <= maxn; j += i)
            noPrime[j] = 1;

    long long offset = n - k + 1;
    iota(a, a + 1000005, 0);
    iota(b, b + 1000005, offset);

    ll rj = 1;

    for (int i = 2; i <= maxn; ++i)
        if (!noPrime[i])
        {
            // cout << i << endl;
            int pw = 0;
            for (int j = i; j <= k; j += i)
            {
                while (a[j] % i == 0)
                {

                    --pw;
                    // ++divisors[j][i];
                    a[j] /= i;
                }
                // divisors[j].push_back(m);
            }

            for (ll j = ((n - k + 1) + i - 1) / i * i; j <= n; j += i)
            {
                // cout << b[j - offset] << endl;
                // cout << j - offset << endl;
                while (b[j - offset] % i == 0)
                {
                    // cout << i << endl;
                    ++pw;
                    // ++divisors[j][i];
                    b[j - offset] /= i;
                }
            }

            rj = (rj * (pw + 1)) % 998244353;
        }

    for (long long i = n - k + 1; i <= n; i++)
        if (b[i - offset] != 1)
            rj = (rj * 2) % 998244353;

    cout << rj << endl;

    // for (int i = 0; i < 40; ++i)
    // {

    //     cout << i << ": ";
    //     for (auto [j, k] : divisors[i])
    //         cout << j << "^" << k << ", ";
    //     cout << endl;
    // }

    return 0;
}