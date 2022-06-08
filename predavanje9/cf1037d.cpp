#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, a[200005], b[200005];
vector<int> g[200005];

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
        sort(g[i].begin(), g[i].end(),
             [](int x, int y)
             {
                 return b[y] > b[x];
             });

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j : g[i])
    //         cout << j << " ";
    //     cout << endl;
    // }

    queue<int> q;
    vector<bool> used(n + 1);
    vector<int> d(n + 1), p(n + 1);

    q.push(1);
    used[1] = 1;
    p[1] = -1;

    vector<int> pth;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        pth.push_back(v);

        for (int u : g[v])
        {
            if (!used[u])
            {
                used[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    // for (int i = 0; i < n; ++i)
    //     cout << pth[i] << " ";
    // cout << endl;

    cout << (equal(pth.begin(), pth.end(), a, a + n) ? "Yes" : "No") << endl;

    return 0;
}
