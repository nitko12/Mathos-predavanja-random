#include <iostream>
using namespace std;

int n, a[100005];

int cnt[100005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        ++cnt[a[i]];

    int ans = 1;
    for (int i = 1 + n % 2; i <= n; i += 2)
    {
        // cout << cnt[i] << " ";
        if (cnt[i] != 2)
            return cout << 0, 0;
    }

    for (int i = 1 + n % 2; i <= n; i += 2)
    {
        ans = (1ll * ans * 2) % 1000000007;
    }

    cout << ans << endl;

    return 0;
}
