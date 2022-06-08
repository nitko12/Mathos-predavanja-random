#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int mul(int a, int b) { return 1LL * a * b % mod; }
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
void adds(int &a, int b) { a = add(a, b); }

class Mat
{
public:
    vector<vector<int>> v;
    int n, m;
    Mat(int _n, int _m, bool k = 0)
    {
        n = _n;
        m = _m;
        v.resize(n);
        for (auto &i : v)
            i.resize(m);

        if (k)
            for (int i = 0; i < min(n, m); ++i)
                v[i][i] = 1;
    }
    Mat(const initializer_list<initializer_list<int>> &l)
    {
        n = l.size();
        m = l.begin()->size();
        v.resize(l.size());
        for (auto i = l.begin(); i < l.end(); ++i)
            for (auto j : *i)
                v[i - l.begin()].push_back(j);
    }
    Mat operator+(const Mat &b) const
    {
        Mat t(n, b.m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                t.v[i][j] = add(v[i][j], b.v[i][j]);
        return t;
    }
    Mat operator*(const Mat &b) const
    {
        Mat t(n, b.m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k)
                    adds(t.v[i][j], mul(v[i][k], b.v[k][j]));
        return t;
    }
    Mat operator^(const ll p) const
    {
        if (p == 0)
            return Mat(n, m, 1);
        Mat t = *this;
        if (p % 2 == 0)
            return (t * t) ^ (p / 2);
        return t * (t ^ (p - 1));
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    Mat a(m, m), b(m, 1);
    for (int i = 0; i < m - 1; ++i)
        a.v[i][i + 1] = 1;

    a.v[m - 1][0] = 1;
    a.v[m - 1][m - 1] = 1;

    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }

    b.v[m - 1][0] = 1;

    a = a ^ n;
    a = a * b;

    cout << a.v[m - 1][0] << endl;
    return 0;
}