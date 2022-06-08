#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
int n;

vector<pair<int, int>> s;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        s.push_back({a, 1});
        s.push_back({b, -1});
    }
    sort(s.begin(), s.end());
    int mx = 0, t = 0;
    for (int i = 0; i < n * 2; ++i)
        t += s[i].second, mx = max(t, mx);
    cout << mx << endl;

    return 0;
}