#include <iostream>
using namespace std;

int n, a[50];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    bool f = 0;
    for (int i = 0; i < (1 << n); ++i)
    {
        int deg = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                deg = (deg + a[j]) % 360;
            else
                deg = (deg - a[j] + 360) % 360;

        // cout << deg << endl;

        if (deg == 0)
            f = 1;
    }

    cout << (f ? "YES" : "NO") << endl;

    return 0;
}
