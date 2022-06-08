#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <set>

using namespace std;
int n, r[200001];
pair<pair<int, int>, int> a[200000];
multiset<pair<int, int>> s;
priority_queue<int, std::vector<int>, std::greater<int>> q;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        ::a[i] = {{a, b}, i};
    }
    sort(a, a + n);
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    int mx = 0;
    for (int j = 0; j < n; ++j)
    {
        auto [a, b] = ::a[j].first;
        auto i = s.begin(), l = s.lower_bound({a, 0});
        while (i != l)
            q.push((*i).second), s.erase(i++);
        mx = max(mx, q.top());
        r[::a[j].second] = q.top();
        s.insert({b, q.top()});
        q.pop();
    }
    cout << mx << endl;
    for (int i = 0; i < n; ++i)
        cout << r[i] << " ";
    cout << endl;

    return 0;
}