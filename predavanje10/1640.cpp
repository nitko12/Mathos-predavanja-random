#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
int n, x;
pair<int, int> a[200000];

vector<pair<int, int>> s;
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        // cout << i << " " << j << " " << a[i].first << " " << a[j].first << endl;
        if (a[i].first + a[j].first == x)
            return cout << a[i].second + 1 << " " << a[j].second + 1 << endl, 0;
        else if (a[i].first + a[j].first < x)
            ++i;
        else
            --j;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
