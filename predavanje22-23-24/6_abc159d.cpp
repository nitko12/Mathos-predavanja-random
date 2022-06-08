#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
int n, a[200005];
map<int, int> m;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++m[a[i]];
    }

    ll sum = 0;
    for (auto i : m)
        sum += (1ll * i.second * (i.second - 1)) / 2;

    for (int i = 0; i < n; ++i)
    {
        cout << sum - m[a[i]] + 1 << endl;
    }
}
