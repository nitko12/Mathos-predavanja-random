#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a[200000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    cout << unique(a, a + n) - a << endl;

    return 0;
}
