#include <map>
#include <vector>
#include <iostream>
using namespace std;

int r, c;
string s[500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int vis[500][500];

bool dfs(int i, int j)
{
    if (i < 0 || j < 0 || i == r || j == c)
        return false;

    if (vis[i][j])
        return false;

    if (s[i][j] == 'P')
        return false;

    if (s[i][j] == 'O')
        return true;

    vis[i][j] = 1;
    for (int k = 0; k < 4; ++k)
        if (dfs(i + dx[k], j + dy[k]))
            return true;
    return false;
};

int main(int argc, char *argv[])
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> s[i];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (s[i][j] == 'V')
                if (dfs(i, j))
                    return cout << "NE\n", 0;

    cout << "DA\n";
}
