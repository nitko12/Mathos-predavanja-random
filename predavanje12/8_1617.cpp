#include <iostream>

typedef long long ll;
using namespace std;

ll mod = (1e9 + 7);

int main()
{
    int n, res = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        res = (1ll * res * 2) % mod;
    cout << res << endl;
    return 0;
}