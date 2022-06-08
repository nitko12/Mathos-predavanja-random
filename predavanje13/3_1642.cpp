#include <iostream>
#include <algorithm>
#include <utility>

#define f first
#define s second

using namespace std;

typedef long long ll;
int n, x, t;
pair<int, int> a[1000];

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> t, a[i] = {t, i};
    sort(a, a + n);
    for (int h = 0; h < n; ++h)
        for (int i = h + 1; i < n; ++i)
        {
            int j = i + 1, k = n - 1;
            while (j < k && j < n && k > i)
            {
                // cout << a[i].f << " " << a[j].f << " " << a[k].f << endl;
                if (a[h].f + a[i].f + a[j].f + a[k].f == x)
                {
                    cout << a[h].s + 1 << " " << a[i].s + 1 << " " << a[j].s + 1 << " " << a[k].s + 1 << endl;
                    return 0;
                }
                if (a[h].f + a[i].f + a[j].f + a[k].f < x)
                    ++j;
                else
                    --k;
            }
        }
    cout << "IMPOSSIBLE" << endl;
}