#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int mn = min(a, b);
        int mx = max(a, b);

        if (mx > 2 * mn)
        {
            cout << "NO" << endl;
            continue;
        }

        a = mn;
        b = mx;

        a %= 3;
        b %= 3;

        mn = min(a, b);
        mx = max(a, b);

        if ((mx == 2 && mn == 1) || (mx == 0 && mn == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
