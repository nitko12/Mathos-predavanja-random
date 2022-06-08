#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
string s[55];
map<string, set<string>> mp;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    for (int i = 0; i < m; ++i)
    {
        string a, b;
        cin >> a >> b;

        mp[a].insert(b);
        mp[b].insert(a);
    }

    set<string> mx;
    for (int i = 0; i < (1 << n); ++i)
    {
        set<string> st;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                st.insert(s[j]);

        bool f = 0;
        for (auto j : st)
        {
            set<string> inter;
            set_intersection(mp[j].begin(),
                             mp[j].end(),
                             st.begin(),
                             st.end(),
                             inserter(inter, inter.begin()));
            if (inter.size() != 0)
                f = 1;
        }

        if (!f && st.size() > mx.size())
            mx = st;
    }

    cout << mx.size() << endl;
    for (auto j : mx)
        cout << j << endl;

    return 0;
}
