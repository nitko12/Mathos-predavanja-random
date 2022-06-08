#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

/*
6
15 Marko
13 Mislav
18 Josip
20 Ana
5 Ivan
5 Ivana
*/

int main()
{
    vector<pair<int, string>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        string s;
        cin >> x >> s;
        v.push_back({x, s});
    }
    auto f = [](pair<int, string> p1,
                pair<int, string> p2)
    {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second > p2.second;
    };
    sort(v.begin(), v.end(), f);
    for (auto &[x, s] : v)
    {
        cout << x << " " << s << endl;
    }
}
