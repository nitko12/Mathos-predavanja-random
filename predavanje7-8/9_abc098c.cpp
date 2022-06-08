#include <iostream>
using namespace std;

int n, a[300005], b[300005];
string s;

int main()
{
    cin >> n >> s;

    for (int i = 1; i <= n; ++i)
        ++(s[i - 1] == 'E' ? a[i] : b[i]);

    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];

    int mn = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        // cout << b[i - 1] << " " << a[n] - a[i] << endl;
        mn = min(mn, i - 1 - a[i - 1] + a[n] - a[i]);
    }
    cout << mn << endl;

    return 0;
}
