#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, dp[1000][1000];
string s[1000];

int f(int x, int y)
{
    if (x == n - 1 && y == n - 1)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];
    int cnt = 0;
    if (x != n - 1 && s[y][x + 1] != '*')
        cnt = (cnt + f(x + 1, y)) % 1000000007;
    if (y != n - 1 && s[y + 1][x] != '*')
        cnt = (cnt + f(x, y + 1)) % 1000000007;
    return dp[y][x] = cnt;
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    if (s[0][0] == '*')
        cout << 0 << endl;
    else
        cout << f(0, 0) << endl;
}