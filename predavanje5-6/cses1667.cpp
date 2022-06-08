#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
int n, m, used[100005], d[100005], p[100005];

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s = 1, u = n;

    queue<int> q;

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    if (!used[u])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int v : path)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}