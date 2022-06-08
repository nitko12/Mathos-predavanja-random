#include <iostream>
using namespace std;

int n, a[200005], b[200005], c[200005];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i % 2 == 0)
            b[i] = a[i];
        else
            c[i] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];
    for (int i = 1; i <= n; ++i)
        c[i] += c[i - 1];

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int s1 = 0, s2 = 0;

        s1 = b[i - 1] + (c[n] - c[i]);
        s2 = c[i - 1] + (b[n] - b[i]);

        cnt += (s1 == s2);
        // cout << s1 << " " << s2 << endl;
    }

    cout << cnt << endl;
    return 0;
}
