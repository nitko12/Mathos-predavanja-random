#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <array>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define INF (ll)1e18

vvii g;
int n, m, k;

array<ll, 2> dist[200005];

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

    for (int i = 1; i <= n; ++i)
        dist[i] = {(ll)1e18, (ll)1e18};
    dist[1] = {0, 0};

    // cost, used, pos
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.emplace(0, 0, 1);

    while (!pq.empty())
    {
        auto [cost, used, pos] = pq.top();
        // cout << pos << " " << used << " " << cost << endl;
        pq.pop();

        ll ccost = dist[pos][used];

        if (ccost != cost)
        {
            continue;
        }
        if (pos == n)
        {
            break;
        }

        for (auto [v, w] : g[pos])
        {
            if (!used)
            {
                long long new_cost = cost + w / 2;
                if (new_cost < dist[v][true])
                {
                    dist[v][true] = new_cost;
                    pq.emplace(new_cost, true, v);
                }
            }
            // but we can always just try the normal cost route
            if (ccost + w < dist[v][used])
            {
                dist[v][used] = cost + w;
                pq.emplace(cost + w, used, v);
            }
        }
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << i << endl;
    //     for (auto [j, w] : g[i])
    //         cout << " " << j << " " << w << endl;
    // }

    cout << dist[n][1] << endl;

    return 0;
}
