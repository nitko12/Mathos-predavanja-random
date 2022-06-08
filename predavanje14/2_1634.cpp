#include <iostream>
#include <cstring>
using namespace std;
 
int n, x, dp[1000005], a[105];
 
int f(int sum)
{
    if (sum == x)
        return 0;
    if (sum > x)
        return 1e9;
    if (dp[sum] != -1)
        return dp[sum];
 
    int mn = 1e9;
    for (int i = 0; i < n; ++i)
        mn = min(mn, 1 + f(sum + a[i]));
 
    return dp[sum] = mn;
}
 
int main()
{
    cin >> n >> x;
 
    memset(dp, -1, sizeof dp);
 
    for (int i = 0; i < n; ++i)
        cin >> a[i];
 
    if (f(0) == 1e9)
        cout << -1 << endl;
    else
        cout << f(0) << endl;
 
    return 0;
}