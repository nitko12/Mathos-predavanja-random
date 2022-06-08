// 雪花飄飄北風嘯嘯
// 天地一片蒼茫
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

string s[500];

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
int vis[500][500];
pair<int, int> par[500][500];

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
    while (par[cur.first][cur.second] != make_pair(-1, -1))
    {
        res += get(cur, par[cur.first][cur.second]);
        cur = par[cur.first][cur.second];
    }

    reverse(all(res));
    cout << "DA\n"
         << cur.first + 1 << " " << cur.second + 1 << '\n'
         << res;
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        cin >> s[i];

    memset(par, -1, sizeof par);
    queue<pair<int, int>> q;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (s[i][j] == 'V')
                q.emplace(i, j), vis[i][j] = 1;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        if (s[i][j] == 'O')
            printans(i, j);

        for (int k = 0; k < 4; ++k)
        {
            int ii = i + dr[k];
            int jj = j + dc[k];
            if (ii < 0 || ii == r || jj < 0 || jj == c || vis[ii][jj])
                continue;
            if (s[ii][jj] == 'P')
                continue;
            vis[ii][jj] = 1;
            par[ii][jj] = {i, j};
            q.emplace(ii, jj);
        }
    }
    cout << "NE";

    return 0;
}
