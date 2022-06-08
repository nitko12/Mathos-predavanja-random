#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int n;
string s;

int pow(int a, int b)
{
    int rj = 1;
    for (int i = 0; i < b; ++i)
        rj = (1ll * rj * a) % mod;
    return rj;
}
int add(int a, int b)
{
    return (a + b) % mod;
}
int sub(int a, int b)
{
    return (a - b + mod) % mod;
}
int mul(int a, int b)
{
    return (1ll * a * b) % mod;
}

int main()
{
    cin >> n >> s;

    int f[30] = {0};

    for (char c : s)
        ++f[c - 'a'];

    int rj = 1;

    for (int i = 0; i < 26; ++i)
        if (f[i])
            rj = mul(rj, (f[i] + 1));

    rj = sub(rj, 1);

    cout << rj << endl;

    return 0;
}
