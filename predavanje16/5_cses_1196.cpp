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

vvii g;
int n, m, k;

priority_queue<ll> dist[200005];

int main()
{
    cin >> n >> m >> k;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
    }

    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0, 1);
    dist[1].push(0);

    while (!pq.empty())
    {
        ll d, u;
        tie(d, u) = pq.top();
        pq.pop();

        if (d > dist[u].top())
            continue;

        for (ii v : g[u])
        {
            ll t = d + v.second;

            if (dist[v.first].size() < k)
            {
                dist[v.first].push(t);
                pq.emplace(t, v.first);
            }
            else if (t < dist[v.first].top())
            {
                dist[v.first].pop();
                dist[v.first].push(t);
                pq.emplace(t, v.first);
            }
        }
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << i << endl;
    //     for (auto [j, w] : g[i])
    //         cout << " " << j << " " << w << endl;
    // }

    vector<ll> rj;
    while (dist[n].size())
    {
        rj.push_back(dist[n].top());
        dist[n].pop();
    }

    reverse(rj.begin(), rj.end());

    for (ll i : rj)
        cout << i << " ";

    return 0;
}
