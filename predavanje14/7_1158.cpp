#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int n, x, a[1000], b[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> old(x + 1), nw(x + 1);
    old[n] = 0;
    for (int p = n - 1; p >= 0; --p)
    {
        for (int s = x; s >= 0; --s)
        {
            nw[s] = old[s];
            if (s + a[p] <= x)
                nw[s] = max(b[p] + old[s + a[p]], nw[s]);
        }
        swap(nw, old);
    }
    cout << old[0] << endl;
}
