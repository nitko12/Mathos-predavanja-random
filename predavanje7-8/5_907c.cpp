#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    int v = (1 << 26) - 1, cnt = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        string a, b;
        cin >> a >> b;

        // for (int i = 0; i < 26; ++i)
        //     cout << !!(v & (1 << i));
        // cout << endl;

        if (a == ".")
        {
            int t = 0;
            for (int j = 0; j < b.size(); ++j)
                t |= 1 << (b[j] - 'a');
            v &= ~t;
        }
        else if (a == "!")
        {
            if (__builtin_popcount(v) == 1)
                ++cnt;

            int t = 0;
            for (int j = 0; j < b.size(); ++j)
                t |= 1 << (b[j] - 'a');
            v &= t;
        }
        else if (a == "?")
        {
            if (__builtin_popcount(v) == 1)
                ++cnt;

            v &= ~(1 << (b[0] - 'a'));
        }
    }
    string a, b;
    cin >> a >> b;

    cout << cnt << endl;

    return 0;
}
