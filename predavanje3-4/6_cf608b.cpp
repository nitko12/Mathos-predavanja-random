#include <iostream>
using namespace std;

int n, m, a[200005], b[200005];
string sa, sb;

int main()
{
    cin >> sa >> sb;
    n = sa.size();
    m = sb.size();

    for (int i = 1; i <= m; ++i)
    {
        a[i] = !(sb[i - 1] - '0') + a[i - 1];
        b[i] = (sb[i - 1] - '0') + b[i - 1];
        // if (sb[i] == '1')
        //     ++a[i];
        // else
        //     ++b[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int t = sa[i] - '0';
        sum += (t) * (a[m - n + i + 1] - a[i]);
        sum += (!t) * (b[m - n + i + 1] - b[i]);
    }

    cout << sum << endl;
    return 0;
}