#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int n, m, a, b, dp[21][1 << 21 + 1], mod = 1e9 + 7;
vector<int> g[21];

int f(int p, int bt)
{
    if (p == n - 1)
        return bt == (1 << n) - 1;
    if (dp[p][bt] != -1)
        return dp[p][bt];
    int sum = 0;
    for (int i : g[p])
    {
        if (~bt & (1 << i))
            sum = (sum + f(i, bt | (1 << i))) % mod;
    }
    return dp[p][bt] = sum;
}

int main()
{
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < m; ++i)
        cin >> a >> b, g[a - 1].push_back(b - 1);
    cout << f(0, 1) << endl;
}