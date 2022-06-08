#include <iostream>
#include <cstring>
using namespace std;

int n, k, a[100005], dp[100005];

int f(int p)
{
    // cout << p << endl;
    if (p == n - 1)
        return 0;
    if (p >= n)
        return 1e9;
    if (dp[p] != -1)
        return dp[p];

    int mn = 1e9;
    for (int i = 1; i <= k; ++i)
        if (p + i <= n - 1)
            mn = min(mn, abs(a[p] - a[p + i]) + f(p + i));

    return dp[p] = mn;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // memset(dp, -1, sizeof dp);
    // cout << f(0) << endl;

    dp[0] = 0;
    for (int i = 1; i < n; ++i)
        dp[i] = 1e9;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i + j < n)
                dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}