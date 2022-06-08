#include <iostream>
using namespace std;

string s;
int n, a[5005], b[5005];

int main()
{
    cin >> s;
    n = s.size();

    for (int i = 1; i <= n; ++i)
        a[i] = (s[i - 1] == 'a');
    for (int i = 1; i <= n; ++i)
        b[i] = a[i] + b[i - 1];

    int mx = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = i; j <= n; ++j)
        {
            int k1 = i - (b[i] - b[0]),
                k2 = (b[j] - b[i]),
                k3 = (n - j) - (b[n] - b[j]);

            mx = max(mx, n - (k1 + k2 + k3));

            // cout << k1 << " " << k2 << " " << k3 << endl;
        }

    cout << mx << endl;

    return 0;
}