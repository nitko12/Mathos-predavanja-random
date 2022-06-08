#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m, s, t;
set<int> g[1005];

vector<int> bfs(int x)
{
    queue<int> q;
    vector<bool> used(n + 5);
    vector<int> d(n + 5, 1e9);

    q.push(x);
    used[x] = 1;
    d[x] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : g[v])
        {
            if (!used[u])
            {
                used[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }

    return d;
}

int main()
{
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        g[u].insert(v);
        g[v].insert(u);
    }

    vector<int> d1 = bfs(s),
                d2 = bfs(t);

    // cout << d1[t] << " " << d2[s] << endl;

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (g[i].find(j) == g[i].end() &&
                !(
                    d1[i] + d2[j] + 1 < d1[t] ||
                    d1[j] + d2[i] + 1 < d1[t]))
            {
                // cout << i << " " << j << endl;
                ++cnt;
            }

    cout << cnt << endl;

    return 0;
}
