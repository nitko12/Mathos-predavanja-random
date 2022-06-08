#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl

int n, d, a[200000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    long long md = a[n / 2], cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += abs(md - a[i]);
    cout << cnt << endl;

    return 0;
}
