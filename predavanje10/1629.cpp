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
        s.emplace_back(b, a);
    }
    sort(s.begin(), s.end());
    int mx = -1, t = 0;
    for (int i = 0; i < n; ++i)
    {
        auto [b, a] = s[i];
        if (a >= mx)
            mx = b, ++t;
    }
    cout << t << endl;

    return 0;
}
