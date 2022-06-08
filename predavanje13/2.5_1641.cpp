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
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int lo = k + 1, hi = n;
                while (lo < hi)
                {
                    int mid = (lo + hi) / 2; // pod
                    if (a[i].first + a[j].first + a[mid].first >= x)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                if (lo != n && a[i].first + a[j].first + a[lo].first == x)
                {
                    cout << a[i].second + 1 << " "
                         << a[j].second + 1 << " "
                         << a[lo].second + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}