#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int n, x, dp[1000000], a[100];

int f(int sum)
{
    if (sum == x)
        return 1;
    if (sum > x)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt = (cnt + f(sum + a[i])) % 1000000007;
    return dp[sum] = cnt;
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    cout << f(0) << endl;
}