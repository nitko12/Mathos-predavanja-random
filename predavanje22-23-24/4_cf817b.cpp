#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define int long long

int n, m, a[100005], b[100005];
int pref[100005], suff[100005];

signed main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];

    sort(b, b + n);

    int ans = 0;

    do
    {
        int x = b[0], y = b[1], z = b[2];

        pref[0] = (a[0] == x);
        for (int i = 1; i < n; ++i)
            pref[i] = pref[i - 1] + (a[i] == x);

        suff[n - 1] = (a[n - 1] == z);
        for (int i = n - 2; i >= 0; --i)
            suff[i] = suff[i + 1] + (a[i] == z);

        for (int i = 1; i < n - 1; ++i)
            if (a[i] == y)
            {
                ans += 1ll * pref[i - 1] * suff[i + 1];
            }

    } while (next_permutation(b, b + 3));

    cout << ans << endl;

    return 0;
}
