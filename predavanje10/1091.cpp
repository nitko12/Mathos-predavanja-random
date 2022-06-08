#include <iostream>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
int n, m, a[200000], b[200000];
int main()
{
    cin >> n >> m;
    multiset<int, greater<int>> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i], s.insert(a[i]);

    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        auto it = s.lower_bound(t);
        if (it == s.end())
            cout << -1 << endl;
        else
            cout << *it << endl, s.erase(it);
        ;

        /*
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(f(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(f(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        */
    }

    return 0;
}