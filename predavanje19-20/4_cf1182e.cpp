#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// n choose r non recursive
ll ncr(ll n, ll r)
{
    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

int mod = 1e9 + 6;

int mul(int a, int b) { return 1LL * a * b % mod; }
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
void adds(int &a, int b) { a = add(a, b); }
int exp(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return exp(mul(a, a), b / 2);
    return mul(a, exp(a, b - 1));
}

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
    vector<int> &operator[](const int p)
    {
        return v[p];
    }
};

ll n, f1, f2, f3, c;

int main()
{
    Mat a = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {-6 + mod, 2, 1, 1, 1},
    };

    Mat b = {
        {1},
        {4},
        {0},
        {0},
        {0},
    };

    cin >> n >> f1 >> f2 >> f3 >> c;
    --n;
    b = (a ^ n) * b;

    // f(n-1)+f(n-2) + n

    Mat cm = {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1}};
    Mat d = {
            {0},
            {1},
            {1},
            {0},
        },
        e = {
            {0},
            {1},
            {0},
        },
        f = {
            {0},
            {0},
            {1},
        };

    d = (cm ^ n) * d;
    e = (cm ^ n) * e;
    f = (cm ^ n) * f;
    ++mod;

    cout << mul(
                mul(exp(c, b[2][0]), exp(f1, d[0][0])),
                mul(exp(f2, e[0][0]), exp(f3, f[0][0])))
         << endl;
    return 0;
}