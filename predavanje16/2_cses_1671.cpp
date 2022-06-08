#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define INF (ll)1e18

void dijkstra(vvii &AdjList, vi &dist, ll s)
{
    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0, s);

    while (!pq.empty())
    {
        ll d, u;
        tie(d, u) = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (ii v : AdjList[u])
        {
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.emplace(dist[v.first], v.first);
            }
        }
    }
}

vvii g;
int n, m;

int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
    }

    vi dist(n + 1, INF);
    dist[1] = 0;

    dijkstra(g, dist, 1);

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << i << endl;
    //     for (auto [j, w] : g[i])
    //         cout << " " << j << " " << w << endl;
    // }

    for (int i = 1; i <= n; ++i)
        cout << dist[i] << " ";

    return 0;
}
