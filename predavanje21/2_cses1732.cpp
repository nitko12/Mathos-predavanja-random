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

const int maxn = 1000000;
int ppow[maxn], pref[maxn + 1];

void pre_hash(const string &s)
{
    for (int i = 0; i < s.size(); ++i)
        pref[i + 1] = add(pref[i], mul(s[i] - 'a' + 1, ppow[i]));
}

int substr_hash(int i, int j)
{
    // cout << pref[j + 1] << " " << pref[i] << endl;
    return sub(pref[j + 1], pref[i]);
}

int hash_f(const string &s)
{
    ll p = 1, h = 0;
    for (int i = 0; i < s.size(); ++i)
        h = add(h, mul(s[i] - 'a' + 1, ppow[i]));
    return h;
}

string s, p;

int main()
{
    cin >> s;

    ppow[0] = 1;
    for (int i = 1; i < maxn; ++i)
        ppow[i] = mul(ppow[i - 1], 31);

    for (int i = 0; i < s.size(); ++i)
        pref[i + 1] = add(pref[i], mul(s[i] - 'a' + 1, ppow[i]));

    // cout << h << endl;

    // for (int i = 1; i <= s.size(); ++i)
    //     cout << pref[i] << " ";
    // cout << endl;

    for (int i = 1; i < s.size(); ++i)
    {
        // i = 2;
        // cout << substr_hash(i, i + p.size() - 1) << endl;
        // cout << mul(ppow[i], h) << endl;

        // cout << mul(ppow[s.size() - 2], substr_hash(0, i - 1)) << endl;
        // cout << mul(ppow[s.size() - i], pref[i]) << endl;

        // // 134875195
        // cout << substr_hash(s.size() - i, s.size() - 1) << endl;

        if (mul(ppow[s.size() - i], pref[i]) ==
            substr_hash(s.size() - i, s.size() - 1))
            cout << i << " ";

        // break;
    }
    cout << endl;

    // cout << cnt << endl;

    return 0;
}
