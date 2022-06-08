#include <iostream>
#include <deque>
using namespace std;

int n, a[1 << 17];

int main()
{
    cin >> n;

    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < (1 << (i - 1)); ++j)
        {
            a[(1 << i) - j - 1] = a[j];
            // cout << (1 << i) - j - 1 << " " << j << endl;
        }
        for (int j = (1 << (i - 1)); j < (1 << n); ++j)
            a[j] |= (1 << (i - 1));
    }

    for (int i = 0; i < (1 << n); ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << !!(a[i] & (1 << j));
        cout << endl;
    }

    return 0;
}