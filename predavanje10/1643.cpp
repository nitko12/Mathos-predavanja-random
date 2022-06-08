#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl

int n, d, a[200000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long ans = a[0], sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        ans = max(ans, sum);
        sum = max(0ll, sum);
    }
    cout << ans << endl;

    return 0;
}
