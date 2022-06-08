#include <iostream>
using namespace std;

int n, pr, sf;
string s;

int main()
{
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        if (s[0] == s[i])
            ++pr;
        else
            break;

    for (int i = n - 1; i >= 0; --i)
        if (s[n - 1] == s[i])
            ++sf;
        else
            break;

    if (s[0] != s[n - 1])
        cout << (pr + sf + 1) % 998244353 << endl;
    else
        cout << (1ll * (pr + 1) * (sf + 1)) % 998244353 << endl;

    return 0;
}
