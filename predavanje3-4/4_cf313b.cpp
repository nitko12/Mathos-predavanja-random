#include <iostream>
using namespace std;

string s;
int n, m, a[100005], b[100005], l, r;

int main()
{
    cin >> s >> m;
    n = s.size();

    for (int i = 1; i <= n; ++i)
        a[i] = (s[i - 1] == s[i]);

    for (int i = 1; i <= n; ++i)
        b[i] = a[i] + b[i - 1];

    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        cout << b[r - 1] - b[l - 1] << endl;
    }
    return 0;
}