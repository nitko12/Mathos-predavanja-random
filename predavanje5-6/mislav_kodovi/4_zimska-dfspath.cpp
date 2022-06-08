#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
const int mod = 1e9 + 7;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int maxn = 500;

char g[maxn][maxn];
pair<int, int> p[maxn][maxn];
bool vis[maxn][maxn];
int r, c;

void printans(int i, int j)
{
    auto get = [](pair<int, int> a, pair<int, int> b)
    {
        if (a.first - b.first == -1)
            return 'U';
        if (a.first - b.first == 1)
            return 'D';
        if (a.second - b.second == -1)
            return 'L';
        return 'R';
    };

    pair<int, int> cur = {i, j};
    string res = "";
    while (p[cur.first][cur.second] != make_pair(-1, -1))
    {
        res += get(cur, p[cur.first][cur.second]);
        cur = p[cur.first][cur.second];
    }

    reverse(all(res));
    cout << "DA\n"
         << cur.first + 1 << " " << cur.second + 1 << '\n'
         << res;

    exit(0);
}

void dfs(int i, int j)
{
    if (g[i][j] == 'O')
    {
        printans(i, j);
    }
    vis[i][j] = true;
    for (int dir = 0; dir < 4; dir++)
    {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (ni < 0 || nj < 0 || ni == r || nj == c || vis[ni][nj] || g[ni][nj] == 'P')
            continue;
        p[ni][nj] = {i, j};
        dfs(ni, nj);
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> g[i][j];
        }
    }

    memset(p, -1, sizeof p);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (g[i][j] == 'V')
            {
                dfs(i, j);
            }
        }
    }

    cout << "NE";
}