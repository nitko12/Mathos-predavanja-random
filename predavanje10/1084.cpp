#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, a[200000], b[200000];

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int cnt = 0;
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (a[i] + k < b[j])
            ++i;
        else if (a[i] - k > b[j])
            ++j;
        else
        {
            ++i;
            ++j;
            ++cnt;
        }
    }
    cout << cnt << endl;

    return 0;
}
