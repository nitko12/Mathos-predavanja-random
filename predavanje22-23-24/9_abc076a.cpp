#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int fact(int n)
{
    int rj = 1;
    for (int i = 2; i <= n; ++i)
        rj = (1ll * rj * i) % mod;
    return rj;
}

int n, k;

int main()
{
    cin >> n >> k;

    if (abs(n - k) >= 2)
        return cout << 0 << endl, 0;

    if (abs(n - k) == 1)
        return cout << (1ll * fact(n) * fact(k)) % mod << endl, 0;

    if (n == k)
        return cout << (2ll * fact(n) * fact(k)) % mod << endl, 0;

    return 0;
}
