#include <iostream>
using namespace std;

int n, a[50];

bool f(int p, int deg)
{
    if (p == n && deg == 0)
        return 1;

    if (p == n)
        return 0;

    return f(p + 1, (deg + a[p]) % 360) ||
           f(p + 1, (deg - a[p] + 360) % 360);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << (f(0, 0) ? "YES" : "NO") << endl;

    return 0;
}
