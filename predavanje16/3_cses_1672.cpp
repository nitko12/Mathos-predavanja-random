#include <iostream>
using namespace std;

long long n, m, q, g[505][505];

int main()
{
    cin >> n >> m >> q;

    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            g[i][j] = (i == j ? 0 : 1e18); //  : inf); usually

    for (int i = 0; i < m; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        g[a][b] = min(c, g[a][b]);
        g[b][a] = min(c, g[b][a]);
    }

    for (int k = 1; k < n + 1; ++k)
        for (int i = 1; i < n + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;

        cout << (g[a][b] == 1e18 ? -1 : g[a][b]) << endl;
    }

    return 0;
}
