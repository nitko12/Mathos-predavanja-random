#include <iostream>
#include <cstring>
using namespace std;

int n, a[100005], b[100005], c[100005], dp[100005][5];

int f(int p, int l)
{
    if (p == n)
        return 0;
    if (l != -1 && dp[p][l] != -1)
        return dp[p][l];

    int mn = -1e9;
    if (l == 0)
    {
        mn = max(mn, b[p] + f(p + 1, 1));
        mn = max(mn, c[p] + f(p + 1, 2));
    }
    else if (l == 1)
    {
        mn = max(mn, a[p] + f(p + 1, 0));
        mn = max(mn, c[p] + f(p + 1, 2));
    }
    else if (l == 2)
    {
        mn = max(mn, a[p] + f(p + 1, 0));
        mn = max(mn, b[p] + f(p + 1, 1));
    }
    else
    {
        mn = max(mn, a[p] + f(p + 1, 0));
        mn = max(mn, b[p] + f(p + 1, 1));
        mn = max(mn, c[p] + f(p + 1, 2));
    }

    return dp[p][l] = mn;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    memset(dp, -1, sizeof dp);
    cout << f(0, -1) << endl;
    return 0;
}