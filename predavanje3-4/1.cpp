#include <iostream>
using namespace std;

long long q, n, m, l, a[30][30][30];

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> n >> m >> l;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int k = 1; k <= l; ++k)
                    cin >> a[i][j][k];

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int k = 1; k <= l; ++k)
                    a[i][j][k] = a[i][j][k] +
                                 a[i - 1][j][k] +
                                 a[i][j - 1][k] +
                                 a[i][j][k - 1] +
                                 -a[i - 1][j - 1][k] +
                                 -a[i][j - 1][k - 1] +
                                 -a[i - 1][j][k - 1] +
                                 a[i - 1][j - 1][k - 1];

        // cout << a[2][2][2] << endl;

        long long mx = -1e12;

        for (int z1 = 1; z1 <= n; ++z1)
            for (int y1 = 1; y1 <= m; ++y1)
                for (int x1 = 1; x1 <= l; ++x1)
                {
                    cout << x1 << " " << y1 << " " << z1 << endl;
                }

        for (int z1 = 1; z1 <= n; ++z1)
            for (int y1 = 1; y1 <= m; ++y1)
                for (int x1 = 1; x1 <= l; ++x1)
                    for (int z2 = z1; z2 <= n; ++z2)
                        for (int y2 = y1; y2 <= m; ++y2)
                            for (int x2 = x1; x2 <= l; ++x2)
                            {
                                long long sum = a[z2][y2][x2] +
                                                -a[z1 - 1][y2][x2] +
                                                -a[z2][y1 - 1][x2] +
                                                -a[z2][y2][x1 - 1] +
                                                a[z1 - 1][y1 - 1][x2] +
                                                a[z2][y1 - 1][x1 - 1] +
                                                a[z1 - 1][y2][x1 - 1] +
                                                -a[z1 - 1][y1 - 1][x1 - 1];

                                mx = max(mx, sum);
                            }
        cout << mx << endl;
        if (q)
            cout << endl;
    }
}
