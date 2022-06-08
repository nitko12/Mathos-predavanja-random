#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
string unos, uzorak;
ll suma[1000005];
int main()
{
    cin >> unos >> uzorak;
    ll p = 1;
    int n{static_cast<int>(unos.size())};
    int m{static_cast<int>(uzorak.size())};
    for (int i(1); i <= n; i++)
    {
        suma[i] = (suma[i - 1] + 1ll * (unos[i] - 'a' + 1) * p % mod) % mod;
        p = 1ll * 31 * p % mod;
    }
    ll s(0);
    p = 1;
    for (int i(0); i < m; i++)
    {
        s = (s + 1ll * (uzorak[i] - 'a' + 1) * p % mod) % mod;
        p = 1ll * 31 * p % mod;
    }
    int c{0};
    for (int i(0); i <= n; i++)
    {
        cout << ((suma[i + m] - suma[i]) % mod + mod) % mod << " " << s << endl;
        if (((suma[i + m] - suma[i]) % mod + mod) % mod == s)
        {
            ++c;
        }
        s = 1ll * s * 31 % mod;
    }
    cout << c;
    return 0;
}