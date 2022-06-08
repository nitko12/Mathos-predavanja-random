#include <iostream>
using namespace std;

string a[505], b[505];

int main()
{
    int n, m, cnt = 0;
    while (cin >> n >> m, n && m)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == '*')
                    continue;

                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
                    dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

                int cnt = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int xx = j + dx[k],
                        yy = i + dy[k];

                    if (0 <= xx && xx < m &&
                        0 <= yy && yy < n &&
                        a[yy][xx] == '*')
                        ++cnt;
                }

                b[i][j] = '0' + cnt;
            }
        }

        if (cnt)
            cout << endl;

        cout << "Field #" << ++cnt << ":" << endl;
        for (int i = 0; i < n; ++i)
            cout << b[i] << endl;
    }
    return 0;
}