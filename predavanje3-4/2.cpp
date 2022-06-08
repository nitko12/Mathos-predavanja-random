#include <iostream>
using namespace std;

int n, q, a[1005][1005], r[200005];
string s[1005];

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = (s[i - 1][j - 1] == '*');
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int sum = a[y2][x2] - a[y1 - 1][x2] - a[y2][x1 - 1] + a[y1 - 1][x1 - 1];
        // 107-60-17+10 = 10+20+4+6
        r[i] = sum;
    }
    for (int i = 0; i < q; ++i)
    {
        cout << r[i];
    }
}