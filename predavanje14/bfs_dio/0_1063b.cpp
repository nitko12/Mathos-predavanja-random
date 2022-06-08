#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

// https://cp-algorithms.com/graph/01_bfs.html

string a[2005];
int n, m, r, c, x, y;

int main()
{
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    deque<tuple<int, int, int, int>> q;
    q.push_back({r - 1, c - 1, x, y});

    int rj = 0;
    while (!q.empty())
    {
        auto [i, j, x, y] = q.front();
        q.pop_front();

        if (a[i][j] == '*')
            continue;
        a[i][j] = '*';

        ++rj;

        if (i > 0 && a[i - 1][j] == '.')
            q.push_front({i - 1, j, x, y});
        if (i + 1 < n && a[i + 1][j] == '.')
            q.push_front({i + 1, j, x, y});
        if (j > 0 && a[i][j - 1] == '.' && x)
            q.push_back({i, j - 1, x - 1, y});
        if (j + 1 < m && a[i][j + 1] == '.' && y)
            q.push_back({i, j + 1, x, y - 1});
    }

    cout << rj;
    // for (int i = 0; i < n; ++i)
    //     cout << a[i] << endl;

    return 0;
}
