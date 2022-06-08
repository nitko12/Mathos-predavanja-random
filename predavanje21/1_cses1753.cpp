#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int p = 31;
int mod = 1e9 + 7;

ll fpow(ll p, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fpow((p * p) % mod, n / 2) % mod;
    return (p * fpow(p, n - 1)) % mod;
}

int main()
{
    string n, m;
    vector<int> v;
    cin >> n >> m;

    int cmp = 0;
    for (int i = 0; i < m.size(); i++)
    {
        cmp = (cmp + ((m[i] - 'a' + 1) * fpow(p, i)) % mod) % mod;
    }

    for (int i = 0; i < n.size(); i++)
    {
        int a = (((n[i] - 'a' + 1) * fpow(p, i))) % mod;
        if (i != 0)
            a = (a + v[i - 1]) % mod;
        v.push_back(a);
    }

    // for (int i : v)
    //     cout << i << endl;

    int rjesenje = 0;
    // novi for kojim obilazis v i usporedujes sumu koju iz njega izracunas s cmp-om
    for (int i = 1; i < n.size() - m.size() + 1; i++)
    {
        cout << cmp << " " << (v[i + m.size() - 1] - v[i - 1] + mod) % mod << endl;
        if (cmp == (v[i + m.size() - 1] - v[i - 1] + mod) % mod)
            rjesenje++;
        cmp = (cmp * p) % mod;
    }

    cout << rjesenje;
    return 0;
}