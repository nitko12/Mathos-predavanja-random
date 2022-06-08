#include <iostream>
using namespace std;

int n, m, x1, y1, x2, y2, a[1005][1005];
string s[1005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = (s[i - 1][j - 1] == '*');

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] += a[i][j - 1] +
                       a[i - 1][j] -
                       a[i - 1][j - 1];

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < m; ++i)
    {
        cin >> y1 >> x1 >> y2 >> x2;

        cout << a[y2][x2] -
                    a[y1 - 1][x2] -
                    a[y2][x1 - 1] +
                    a[y1 - 1][x1 - 1]
             << endl;
    }

    return 0;
}