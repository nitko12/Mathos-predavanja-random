#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10001;

template <class T>
class FenwickTree
{
    vector<T> ft;

public:
    FenwickTree() : ft(maxn)
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

FenwickTree<long long int> F[10];
int l[maxn];

int main()
{
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> l[i];
    for (int i = 1; i <= n; ++i)
    {
        F[l[i] % m].adjust(i, l[i]);
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int p, r;
            cin >> p >> r;
            F[l[p] % m].adjust(p, -l[p]);
            cout << (l[p] += r) << "\n";
            F[l[p] % m].adjust(p, l[p]);
        }
        else if (c == '-')
        {
            int p, r;
            cin >> p >> r;
            F[l[p] % m].adjust(p, -l[p]);
            if (l[p] >= r)
                l[p] -= r;
            cout << l[p] << "\n";
            F[l[p] % m].adjust(p, l[p]);
        }
        else
        {
            int l, r, mod;
            cin >> l >> r >> mod;
            cout << F[mod].rsq(l, r) << "\n";
        }
    }
    return 0;
}