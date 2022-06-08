#include <iostream>
using namespace std;

long long n;

long long mn = 1e18;
int f(int p, long long val)
{
    if (p == n && val >= n)
        mn = min(mn, val);
}

int main()
{
    cin >> n;

    long long mn = 1e18;
    for (int i = 2; i <= 10; i += 2)
    {
        for (int j = 0; j < (1 << i); ++j)
        {
            long long t = 0, cnt4 = 0, cnt7 = 0;
            for (int k = 0; k < i; ++k)
            {
                ++((j & (1 << k)) ? cnt4 : cnt7);

                t += ((j & (1 << k)) ? 4 : 7);
                t *= 10;
            }
            t /= 10;

            if (cnt4 != cnt7)
                continue;

            if (t >= n)
                mn = min(mn, t);

            // cout << t << endl;
        }
    }

    cout << mn << endl;

    return 0;
}
