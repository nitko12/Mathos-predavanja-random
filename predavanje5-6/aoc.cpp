#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, v[105][105];
string s[105];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int f(int i, int j)
{
    // cout << i << " " << j << endl;

    int sum = 1;
    v[i][j] = 1;
    for (int k = 0; k < 4; ++k)
    {
        int xx = j + dx[k];
        int yy = i + dy[k];

        if (0 <= xx && xx < s[i].size() &&
            0 <= yy && yy < n &&
            !v[yy][xx] &&
            s[yy][xx] != '9'
            // s[yy][xx] <= s[i][j]
        )
            sum += f(yy, xx);
    }

    return sum;
}

int main()
{
    while (cin >> s[n++])
        ;
    --n;

    // cout << f(0, 0) << endl;

    vector<int> b;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < s[i].size(); ++j)
        {
            if (!v[i][j] && s[i][j] != '9')
            {
                b.push_back(f(i, j));
                // cout <<  << endl;
            }
        }

    sort(b.begin(), b.end());

    cout << 1ll * b[b.size() - 1] * b[b.size() - 2] * b[b.size() - 3] << endl;

    // int sum = 0;
    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < s[i].size(); ++j)
    //     {
    //         int dx[] = {-1, 0, 0, 1};
    //         int dy[] = {0, -1, 1, 0};

    //         int f = 0;
    //         for (int k = 0; k < 4; ++k)
    //         {
    //             int xx = j + dx[k];
    //             int yy = i + dy[k];

    //             if (0 <= xx && xx < s[i].size() &&
    //                 0 <= yy && yy < n &&
    //                 s[yy][xx] <= s[i][j])
    //                 f = 1;
    //         }

    //         if (!f)
    //         {
    //             cout << i << " " << j << endl;
    //             sum += s[i][j] - '0' + 1;
    //         }
    //     }
    // cout << sum << endl;

    return 0;
}