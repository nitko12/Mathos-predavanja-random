#include <iostream>
using namespace std;

const int MAXN = 1 << 19; // 2.6e5
int N = 400000;
int seg[2 * MAXN]; // root is seg[1]

int n, m;

void update(int p, int val)
{
    int d = 0;
    for (seg[p += (1 << n) - 1] = val; p > 0; p >>= 1, ++d)
    {
        if (d % 2 == 0)
            seg[p >> 1] = seg[p] | seg[p ^ 1];
        else
            seg[p >> 1] = seg[p] ^ seg[p ^ 1];
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < (1 << n); ++i)
    {
        int t;
        cin >> t;
        update(i + 1, t);
    }

    for (int i = 0; i < m; ++i)
    {
        int p, b;
        cin >> p >> b;

        update(p, b);
        cout << seg[1] << endl;
    }

    return 0;
}