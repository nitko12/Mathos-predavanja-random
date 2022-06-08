#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5 + 1;

long long dp[mx];
int w[101], v[101];

int main()
{
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
        cin >> w[i] >> v[i];
    for (int i = 0; i < mx; ++i)
        dp[i] = 1e18;

    dp[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = mx - 1; j >= 0; j--)
        {
            if (dp[j] + w[i] <= W)
                dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
        }
    }

    for (int i = mx - 1; i >= 0; i--)
    {
        if (dp[i] != 1e18)
        {
            cout << i << endl;
            break;
        }
    }
}