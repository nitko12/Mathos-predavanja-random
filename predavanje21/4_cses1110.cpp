#include <iostream>
using namespace std;

#define ll long long

const int mod = 1e9 + 9;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int sub(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}

const int maxn = 3000000;
int ppow[maxn], pref[maxn + 1];

string s, p;

int substr_hash(int i, int j)
{
    return mul(ppow[(s.size() - i)], sub(pref[j + 1], pref[i]));
}

int hash_f(const string &s)
{
    ll p = 1, h = 0;
    for (int i = 0; i < s.size(); ++i)
        h = add(h, mul(s[i] - 'a' + 1, ppow[i]));
    return h;
}

int main()
{
    cin >> s;
    s = s + s;

    ppow[0] = 1;
    for (int i = 1; i < maxn; ++i)
        ppow[i] = mul(ppow[i - 1], 31);

    for (int i = 0; i < s.size(); ++i)
        pref[i + 1] = add(pref[i], mul(s[i] - 'a' + 1, ppow[i]));

    int best = 0;
    for (int i = 0; i < s.size() / 2; ++i)
    {

        int lo = 0, hi = s.size() / 2;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (substr_hash(i, i + mid) !=
                substr_hash(best, best + mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        if (lo == s.size() / 2)
            continue;

        if (s[i + lo] < s[best + lo])
        {
            best = i;
            // cout << best << endl;
        }
    }

    cout << s.substr(best, s.size() / 2) << endl;

    return 0;
}
