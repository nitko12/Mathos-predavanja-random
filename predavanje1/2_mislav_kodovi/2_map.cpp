#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;

int main()
{
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        string s;
        cin >> x >> s;
        m[s] = x;
    }
    for (auto [x, s] : m)
        cout << x << ' ' << s << endl;
}
