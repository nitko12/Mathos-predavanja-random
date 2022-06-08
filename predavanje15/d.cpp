#include <iostream>
#include <cstring>
using namespace std;

#define int long long

int N, W, w[100005], v[100005], dp[105][100005];

int f(int p, int w)
{
    if (w > W)
        return -1e9;
    if (p == N)
        return 0;
    if (p > N)
        return -1e9;

    if (dp[p][w] != -1)
        return dp[p][w];

    return dp[p][w] = max(f(p + 1, w), v[p] + f(p + 1, w + ::w[p]));
}

signed main()
{
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
        cin >> w[i] >> v[i];

    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << endl;

    return 0;
}