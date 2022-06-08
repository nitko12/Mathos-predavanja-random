#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
string s;
string a;
int mod = 1e9 + 7;

int tick = 1;
int pr[1000005][26];
int pr2[1000005];
int dp[1000005];

void add2(int &a, int b)
{
    a = (a + b) % mod;
}

int f(int p)
{
    if (p == n)
        return 1;
    if (dp[p] != -1)
        return dp[p];
    int node = 0;
    int sm = 0;
    for (int i = p; i < n; ++i)
    {
        if (pr[node][s[i] - 'a'] != -1)
            node = pr[node][s[i] - 'a'];
        else
            break;
        if (pr2[node] == 1)
            add2(sm, f(i + 1));
    }
    return dp[p] = sm;
}

void t(string &s)
{
    int node = 0;
    for (char c : s)
    {
        int x = c - 'a';
        if (pr[node][x] == -1)
            pr[node][x] = tick++;
        node = pr[node][x];
    }
    pr2[node] = 1;
}

int main()
{
    cin >> s >> m;
    n = s.size();
    memset(pr, -1, sizeof pr);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < m; ++i)
    {
        cin >> a;
        t(a);
    }
    cout << f(0) << endl;
    return 0;
}