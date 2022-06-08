#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define int long long

int n,
    m, d[5005], p[5005];
vector<tuple<int, int, int>> g;

signed main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        d[i] = 1e18;
    d[1] = 0;

    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        g.emplace_back(a, b, w);
    }

    for (int i = 0; i < n; ++i)
        for (const auto t : g)
        {
            int a, b, w;
            tie(a, b, w) = t;
            if (d[a] + w < d[b])
            {
                d[b] = d[a] + w;
                p[b] = a;
            }
        }

    for (const auto t : g)
    {
        int a, b, w;
        tie(a, b, w) = t;
        if (d[b] > d[a] + w)
        {
            cout << "YES" << endl;

            // cout << b << " " << p[b] << " " << p[p[b]] << endl;

            vector<int> v;

            int r = p[b];
            for (int i = 0; i < n - 1; ++i)
                r = p[r];

            v.push_back(r);
            int _r = r;
            r = p[r];

            // cout << r << " " << p[r] << " " << p[p[r]] << endl;
            while (r != _r)
            {
                // cout << r << endl;
                v.push_back(r);
                r = p[r];
            }

            reverse(v.begin(), v.end());
            for (int i : v)
                cout << i << " ";
            cout << v[0] << endl;

            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
