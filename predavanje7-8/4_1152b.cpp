#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<int> v;
int cnt = 0;

void f(long long n)
{
    // cout << n << endl;
    if (n <= 1)
        return;

    int msb = 0;
    for (int i = 0; i < 40; ++i)
        if (n & (1ll << i))
            msb = i;

    // cout << msb << endl;
    if (n == (1ll << (msb + 1)) - 1)
        return;

    if (n == (1ll << msb))
    {
        v.push_back(msb);
        ++cnt;
        return;
    }

    // cout << n << " " << (1ll << (msb + 1)) - 1 << endl;

    n ^= (1ll << (msb + 1)) - 1;
    ++cnt;
    n += 1;
    ++cnt;

    // cout << n << endl
    //      << endl;

    v.push_back(msb + 1);

    f(n);
}

int main()
{
    cin >> n;
    f(n);

    cout << cnt << endl;
    // reverse(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}
