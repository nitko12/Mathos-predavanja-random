#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
int a[1000005];

int f(int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (a[p] != -1)
        return a[p];

    int rj = 0;
    for (int i = 1; i <= 6; ++i)
        rj = (rj + f(p - i)) % mod;

    return a[p] = rj;
}

int main()
{
    memset(a, -1, sizeof a);
    int n;

    cin >> n;
    cout << f(n) << endl;
    return 0;
}