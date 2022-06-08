#include <bits/stdc++.h>
using namespace std;

string s[500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        cin >> s[i];

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (s[i][j] != 'O')
                continue;
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || y < 0 || x == r || y == c)
                    continue;
                if (s[x][y] == 'V')
                    return cout << "NE\n", 0;
            }
        }
    }

    cout << "DA\n";
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
            cout << (s[i][j] == '.' ? 'P' : s[i][j]);
        cout << '\n';
    }

    return 0;
}
