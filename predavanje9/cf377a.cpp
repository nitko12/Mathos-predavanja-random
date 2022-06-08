#include <iostream>
using namespace std;

int n, m, k, vis[505][505], cnt;
string a[505];

void dfs(int x, int y)
{
    // cout << x << " " << y << endl;
    // a[y][x] = 'X';
    --cnt;

    if (cnt == 0)
    {
        // cout << "aaa" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                if (vis[i][j] || a[i][j] == '#')
                    cout << a[i][j];
                else
                    cout << "X";
            cout << endl;
        }

        // for (int i = 0; i < n; ++i)
        //     cout << a[i] << endl;
        exit(0);
    }

    int dx[] = {-1, 0, 0, 1},
        dy[] = {0, -1, 1, 0};

    for (int k = 0; k < 4; ++k)
    {
        int i = dy[k], j = dx[k];
        if (0 <= x + j && x + j < m &&
            0 <= y + i && y + i < n &&
            a[y + i][x + j] == '.' &&
            !vis[y + i][x + j])
        {
            vis[y + i][x + j] = 1;
            dfs(x + j, y + i);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.')
                ++cnt;
    cnt -= k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.')
            {
                vis[i][j] = 1;
                dfs(j, i);
                break;
            }

    return 0;
}
