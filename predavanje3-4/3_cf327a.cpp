#include <iostream>
using namespace std;

int n, a[105], b[105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        b[i] = (a[i] ? -1 : 1) + b[i - 1];

    // for (int i = 1; i <= n; ++i)
    //     cout << (a[i] ? -1 : 1) << " ";
    // cout << endl;
    // for (int i = 1; i <= n; ++i)
    //     cout << b[i] << " ";
    // cout << endl;

    int mxv = 0, mxi = 1, mxj = 1;
    for (int i = 1; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            // cout << b[j] - b[i - 1] << endl;
            if (b[j] - b[i - 1] > mxv)
            {
                mxv = b[j] - b[i - 1];
                mxi = i;
                mxj = j;
            }
        }

    // cout << mxi << " " << mxj << endl;

    for (int i = mxi; i <= mxj; ++i)
        a[i] = !a[i];

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += a[i];

    cout << cnt << endl;
    return 0;
}