#include <iostream>
#include <cmath>
using namespace std;

string s[1000];
int n, m, cnt = 0;

void dfs(int y, int x)
{
    s[y][x] = '0';
    int dx[] = {-1, 0, 0, 1},
        dy[] = {0, -1, 1, 0};
    for (int i = 0; i < 4; ++i)
        if (0 <= y + dy[i] && y + dy[i] < n && 0 <= x + dx[i] && x + dx[i] < m)
            if (s[y + dy[i]][x + dx[i]] != '0' && s[y + dy[i]][x + dx[i]] != '#')
                dfs(y + dy[i], x + dx[i]);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '.')
                ++cnt, dfs(i, j);
    cout << cnt << endl;

    return 0;
}
