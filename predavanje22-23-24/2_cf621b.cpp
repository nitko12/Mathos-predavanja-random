#include <iostream>
#include <map>
using namespace std;

int n;
int x[200005], y[200005];
map<int, int> a, b;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt += a[x[i] + y[i]];
        cnt += b[x[i] - y[i]];

        ++a[x[i] + y[i]];
        ++b[x[i] - y[i]];
    }

    cout << cnt << endl;

    return 0;
}
