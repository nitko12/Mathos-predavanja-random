#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const int mod = 1e9 + 9, mod2 = 1e9 + 7;
int add1(int a, int b) { return (a += b) < mod ? a : a - mod; }
int sub1(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul1(int a, int b) { return 1LL * a * b % mod; }
int pwr1(int a, int p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul1(a, pwr1(a, p - 1));
    return pwr1(mul1(a, a), p / 2);
}

int add2(int a, int b) { return (a += b) < mod2 ? a : a - mod2; }
int sub2(int a, int b) { return (a -= b) >= 0 ? a : a + mod2; }
int mul2(int a, int b) { return 1LL * a * b % mod2; }
int pwr2(int a, int p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul2(a, pwr2(a, p - 1));
    return pwr2(mul2(a, a), p / 2);
}

const int maxn = 1000000;
int ppow[maxn], ppow2[maxn], pref[maxn + 1], pref2[maxn + 1];

int substr_hash1(int i, int j)
{
    // cout << pref[j + 1] << " " << pref[i] << endl;
    return sub1(pref[j + 1], pref[i]);
}

int hash_f1(const string &s)
{
    ll p = 1, h = 0;
    for (int i = 0; i < s.size(); ++i)
        h = add1(h, mul1(s[i] - 'a' + 1, ppow[i]));
    return h;
}

int substr_hash2(int i, int j)
{
    // cout << pref[j + 1] << " " << pref[i] << endl;
    return sub2(pref2[j + 1], pref2[i]);
}

int hash_f2(const string &s)
{
    ll p = 1, h = 0;
    for (int i = 0; i < s.size(); ++i)
        h = add2(h, mul2(s[i] - 'a' + 1, ppow2[i]));
    return h;
}

string s, p, t;

int main()
{
    cin >> s >> p >> t;

    ppow[0] = ppow2[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        ppow[i] = mul1(ppow[i - 1], 31);
        ppow2[i] = mul2(ppow2[i - 1], 29);
    }

    for (int i = 0; i < s.size(); ++i)
    {
        pref[i + 1] = add1(pref[i], mul1(s[i] - 'a' + 1, ppow[i]));
        pref2[i + 1] = add2(pref2[i], mul2(s[i] - 'a' + 1, ppow2[i]));
    }

    int hp1 = mul1(hash_f1(p), ppow[s.size()]);
    int ht1 = mul1(hash_f1(t), ppow[s.size()]);

    int hp2 = mul2(hash_f2(p), ppow2[s.size()]);
    int ht2 = mul2(hash_f2(t), ppow2[s.size()]);

    vector<pair<int, int>> v;
    int cnt = 0;
    for (int i = 0; i < (int)s.size() - (int)p.size() + 1; ++i)
    {
        for (int j = i; j < (int)s.size() - (int)t.size() + 1; ++j)
        {
            int h1 = mul1(ppow[s.size() - i], substr_hash1(i, i + p.size() - 1));
            int h2 = mul1(ppow[s.size() - j], substr_hash1(j, j + t.size() - 1));

            int h12 = mul2(ppow2[s.size() - i], substr_hash2(i, i + p.size() - 1));
            int h22 = mul2(ppow2[s.size() - j], substr_hash2(j, j + t.size() - 1));

            int hh1 = mul1(ppow[s.size() - i], substr_hash1(i, j + t.size() - 1));
            int hh2 = mul2(ppow2[s.size() - i], substr_hash2(i, j + t.size() - 1));

            if (h1 == hp1 &&
                h2 == ht1 &&
                h12 == hp2 &&
                h22 == ht2 &&
                i + p.size() - 1 <= j + t.size() - 1)
            {
                v.push_back({hh1, hh2});
                ++cnt;
            }
        }
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    // for (int i : v)
    //     cout << i << " ";
    // cout << endl;

    cout << v.size() << endl;

    // {
    //     if (mul(ppow[s.size() - i], pref[i]) ==
    //         substr_hash(s.size() - i, s.size() - 1))
    //         cout << i << " ";
    // }
    // cout << endl;

    return 0;
}
