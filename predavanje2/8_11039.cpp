#include <iostream>
#include <algorithm>
using namespace std;

int p, n, a[500005];

int main()
{
    cin >> p;

    while (p--)
    {
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a + n, [](int a, int b)
             { return abs(a) > abs(b); });

        int mx1 = 0, mx2 = 0, c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < 0 && c == 0)
                ++mx1, c = 1;
            else if (a[i] > 0 && c == 1)
                ++mx1, c = 0;
        }
        c = 1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < 0 && c == 0)
                ++mx2, c = 1;
            else if (a[i] > 0 && c == 1)
                ++mx2, c = 0;
        }

        cout << max(mx1, mx2) << endl;

        // for (int i = 0; i < n; ++i)
        //     cout << a[i] << " ";
        // cout << endl;
    }
    return 0;
}