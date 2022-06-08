#include <iostream>
using namespace std;

int n, m, l[100005], r[100005], a[100005], c[100005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> l[i] >> r[i];

    for (int i = 0; i < m; ++i)
        a[l[i]] += 1, a[r[i] + 1] += -1;

    c[1] = a[1];
    for (int i = 2; i <= n; ++i)
        c[i] = c[i - 1] + a[i];

    int rj = 0;
    for (int i = 1; i <= n; ++i)
        if (c[i] == m)
            ++rj;

    cout << rj << endl;
    return 0;
}