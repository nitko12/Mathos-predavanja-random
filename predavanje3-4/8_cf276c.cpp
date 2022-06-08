#include <iostream>
#include <algorithm>
using namespace std;
long long l[300001], r[300000];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> l[i];

    sort(l, l + n);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        ::r[l - 1] += 1;
        ::r[r] -= 1;
    }

    for (int i = 0; i < n; ++i)
        if (i != 0)
            r[i] += r[i - 1];

    sort(r, r + n);
    long long s = 0;

    for (int i = 0; i < n; ++i)
        s += r[i] * l[i];
    cout << s << "\n";

    return 0;
}