#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int n, k, t, d[10];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
        cin >> t, d[t] = 1;

    for (int i = n;; ++i)
    {
        bool f = 0;
        t = i;
        while (t)
        {
            if (d[t % 10])
            {
                f = 1;
                break;
            }
            t /= 10;
        }

        if (!f)
            return cout << i << endl, 0;
    }
    return 0;
}
