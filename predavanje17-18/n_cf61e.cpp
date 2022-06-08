#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int a[1000000], b[1000000], t[1000000], c[1000000], n;

template <class T>
class FenwickTree
{
    vector<T> ft;

public:
    FenwickTree(int n) : ft(n + 1)
    {
    }
    T rsq(int b)
    {
        T sum = 0;
        for (; b; b -= (b & (-b)))
            sum += ft[b];
        return sum;
    }
    T rsq(int a, int b)
    {
        return rsq(b) - rsq(a - 1);
    }
    T q(int x)
    {
        return rsq(x) - rsq(x - 1);
    }
    void adjust(int k, T v)
    {
        for (; k < ft.size(); k += (k & (-k)))
            ft[k] += v;
    }
};

template <class T>
class RangeFT
{
private:
    FenwickTree<T> mul, add;

public:
    RangeFT(int n) : mul(n), add(n)
    {
    }
    T rsq(int a)
    {
        return mul.rsq(a) * a + add.rsq(a);
    }
    T rsq(int a, int b)
    {
        return rsq(b) - rsq(a - 1);
    }
    void adjust(int l, int r, T v)
    {
        mul.adjust(l, v);
        mul.adjust(r, -v);
        add.adjust(l, -v * (l - 1));
        add.adjust(r, v * r);
    }
};

FenwickTree<ll> before(1000001), after(1000001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    for (int i = 0; i < n; ++i)
        c[i] = (lower_bound(b, b + n, a[i]) - b) + 1;
    for (int i = 1; i < n; ++i)
        after.adjust(c[i], 1);
    ll rj = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        before.adjust(c[i - 1], 1);
        after.adjust(c[i], -1);
        ll a, b;
        if (c[i] != n)
            a = before.rsq(c[i] + 1, n);
        else
            a = 0;
        if (c[i] != 1)
            b = after.rsq(1, c[i] - 1);
        else
            b = 0;
        rj += a * b;
    }
    cout << rj << endl;
    return 0;
}