#include <iostream>
#include <algorithm>
#include <utility>

#define f first
#define s second

using namespace std;

typedef long long ll;
int n, x, t;
pair<int, int> a[5000];

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> t, a[i] = {t, i};
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            // cout << a[i].f << " " << a[j].f << " " << a[k].f << endl;
            if (a[i].f + a[j].f + a[k].f == x)
            {
                cout << a[i].s + 1 << " " << a[j].s + 1 << " " << a[k].s + 1 << endl;
                return 0;
            }
            if (a[i].f + a[j].f + a[k].f < x)
                ++j;
            else
                --k;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}