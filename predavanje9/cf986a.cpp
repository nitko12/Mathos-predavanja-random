#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, s, a[100005];
vector<int> g[100005], p[105], r[100005];

void bfs(int x)
{
    queue<int> q;
    vector<bool> used(n + 1);
    vector<int> d(n + 1, 1e9);

    // cout << ::p[x].size() << endl;
    for (int i : ::p[x])
    {
        q.push(i);
        d[i] = 0;
        used[i] = 1;
        r[i].push_back(0);
    }

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
                r[u].push_back(d[u]);
            }
        }
    }

    // if (::p[x].size())
    // {
    //     for (int i = 1; i <= n; ++i)
    //         cout << d[i] << " ";
    //     cout << endl;
    // }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> k >> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        p[a[i]].push_back(i + 1);
        // cout << p[a[i]].size() << endl;
    }

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i <= 100; ++i)
        bfs(i);

    for (int i = 1; i <= n; ++i)
    {
        sort(r[i].begin(), r[i].end());

        // for (int j = 0; j < r[i].size(); ++j)
        //     cout << r[i][j] << " ";
        // cout << endl;

        int cnt = 0;
        // cout << p[i].size() << endl;
        for (int j = 0; j < s; ++j)
            cnt += r[i][j];
        cout << cnt << " ";
    }
    cout << endl;

    return 0;
}
