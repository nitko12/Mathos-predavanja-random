#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int prosti = 31;

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int ppow[2000005];

int fpow(int a, int b)
{
    if (ppow[b] != -1)
        return ppow[b];
    if (b == 0)
        return 1;
    int re = fpow(a, b / 2);
    if (b % 2 == 1)
        return ppow[b] = mul(a, mul(re, re));
    return ppow[b] = mul(re, re);
}
int inv(int x)
{
    return fpow(x, mod - 2);
}

string a, b;
vector<int> pref;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(ppow, -1, sizeof ppow);
    cin >> a;
    b = a + a;
    pref.push_back(0);
    int p = 1;
    for (int i = 1; i <= b.size(); i++)
    {
        pref.push_back(add(pref[i - 1], mul((b[i - 1] - 'a' + 1), p)));
        p = mul(p, prosti);
    }
    int best = 0;
    for (int i = 1; i < a.size(); i++)
    {
        int lo = 0;
        int hi = a.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (sub(pref[i + mid + 1], pref[i]) != mul(sub(pref[best + mid + 1], pref[best]), fpow(prosti, i - best)))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if (lo == a.size())
        {
            continue;
        }
        if (b[i + lo] < b[best + lo])
        {
            best = i;
        }
    }
    for (int i = best; i < best + a.size(); i++)
    {
        cout << b[i];
    }

    return 0;
}