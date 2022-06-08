#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
int n;
string a[100005];
map<string, int> m;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        string b = a[i];
        sort(b.begin(), b.end());
        ++m[b];
    }

    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        string b = a[i];
        sort(b.begin(), b.end());
        sum += m[b] - 1;
    }

    cout << sum / 2 << endl;
    return 0;
}
