#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, a[1000][1000];
string s[1000];

void bfs(int x, int y)
{
    queue<int> q;
    q.push(x + y * m);
    a[y][x] = 0;
    while (!q.empty())
    {
        int tx = q.front() % m, ty = q.front() / m;
        q.pop();
        int dx[] = {-1, 0, 0, 1},
            dy[] = {0, -1, 1, 0};
        for (int i = 0; i < 4; ++i)
        {
            int xx = tx + dx[i],
                yy = ty + dy[i];
            if (0 <= xx && xx < m &&
                0 <= yy && yy < n &&
                a[yy][xx] == -1 &&
                (s[yy][xx] == '.' || s[yy][xx] == 'B'))
            {
                a[yy][xx] = a[ty][tx] + 1;
                q.push(xx + yy * m);
            }
        }
    }
}

string p(int x, int y)
{
    if (s[y][x] == 'A')
        return "";
    int dx[] = {-1, 0, 0, 1},
        dy[] = {0, -1, 1, 0};
    char l[] = {'R', 'D', 'U', 'L'};
    for (int i = 0; i < 4; ++i)
    {
        int xx = x + dx[i],
            yy = y + dy[i];
        if (0 <= xx && xx < m &&
            0 <= yy && yy < n &&
            a[yy][xx] == a[y][x] - 1)
            return p(xx, yy) + l[i];
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    memset(a, -1, sizeof a);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'A')
                bfs(j, i);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'B')
                if (a[i][j] != -1)
                    cout << "YES" << endl
                         << a[i][j] << endl
                         << p(j, i) << endl;
                else
                    cout << "NO" << endl;
    return 0;
}