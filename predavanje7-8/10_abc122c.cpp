#include <iostream>
using namespace std;

int n, q, a[100005], l, r;
string s;

int main()
{
    cin >> n >> q >> s;

    for (int i = 1; i <= n - 1; ++i)
        a[i] = (s[i - 1] == 'A' && s[i - 1 + 1] == 'C');

    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    while (q--)
    {
        cin >> l >> r;

        cout << a[r - 1] - a[l - 1] << endl;
    }

    return 0;
}
