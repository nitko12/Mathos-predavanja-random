#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[3005][3005], n, m;

int lcs(int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n - 1][m - 1] != -1)
        return dp[n - 1][m - 1];

    if (a[n - 1] == b[m - 1])
    {
        dp[n - 1][m - 1] = 1 + lcs(n - 1, m - 1);

        return dp[n - 1][m - 1];
    }
    else
    {
        dp[n - 1][m - 1] = max(lcs(n, m - 1),
                               lcs(n - 1, m));

        return dp[n - 1][m - 1];
    }
}

int main()
{
    cin >> a >> b;

    n = a.size();
    m = b.size();

    memset(dp, -1, sizeof dp);
    cout << lcs(n, m);

    return 0;
}