#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, x, dp[1000000], a[100];

int f(int sum)
{
    if (sum == 0)
        return 0;
    if (sum < 0)
        return 99999999;
    if (dp[sum] != -1)
        return dp[sum];
    int d[10] = {0}, s2 = sum;
    while (s2 != 0)
        d[s2 % 10] = 1, s2 /= 10;
    int mn = 99999999;
    for (int i = 1; i < 10; ++i)
        if (d[i])
            mn = min(mn, 1 + f(sum - i));
    return dp[sum] = mn;
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << f(n) << endl;
}