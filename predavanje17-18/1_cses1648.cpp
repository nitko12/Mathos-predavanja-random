#include <iostream>
#include <vector>
using namespace std;

int n, L, R, s, q, t;

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

int main()
{
    cin >> n >> q;
    FenwickTree<long long> f(n);
    for (int i = 1; i <= n; ++i)
        cin >> t, f.adjust(i, t);

    for (int i = 0; i < q; ++i)
    {
        cin >> s >> L >> R;
        if (s - 1)
        {
            cout << f.rsq(L, R) << endl;
        }
        else
        {
            f.adjust(L, R - f.q(L));
        }
    }
    return 0;
}