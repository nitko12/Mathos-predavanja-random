#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int n, x, dp[1000000], a[100];

int f(int sum)
{
    if (sum == x)
        return 0;
    if (sum > x)
        return 99999999;
    if (dp[sum] != -1)
        return dp[sum];
    int mn = 999999999;
    for (int i = 0; i < n; ++i)
        mn = min(mn, 1 + f(sum + a[i]));
    return dp[sum] = mn;
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    int sol = f(0);
    if (sol >= 100000000)
        sol = -1;
    cout << sol << endl;
}
// 1 2 3 4 5 6 7