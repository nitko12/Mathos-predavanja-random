#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

typedef long long ll;

int n, k;
int dp[1005][1005];

int f(int p, int l)
{
    if (p == n)
        return 1;

    if (l != -1 && dp[p][l] != -1)
        return dp[p][l];

    int rj = 0;
    for (int i = 0; i < k; ++i)
        if (i != k)
            rj += f(p + 1, i);

    return (l != -1 ? (dp[p][l] = rj) : rj);
}

int main()
{
    cin >> n >> k;

    // memset(dp, -1, sizeof(dp));

    // cout << f(0, -1) << endl;

    int rj = k;
    for (int i = 1; i < n; ++i)
        rj *= (k - 1);

    cout << rj << endl;

    return 0;
}
