#include <iostream>
#include <algorithm>
using namespace std;

int n, x, a[200000];

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int cnt = 0, i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] + a[j] > x)
            ++cnt, --j;
        else
            ++cnt, ++i, --j;
    }
    cout << cnt << endl;

    return 0;
}
