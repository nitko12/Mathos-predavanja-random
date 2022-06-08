#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
using namespace std;

int n, k;
string s;

int main()
{
    cin >> n >> k >> s;

    set<string> st;

    queue<string> q;

    int rj = 0;
    q.push(s);
    st.insert(s);
    while (!q.empty() && st.size() < k)
    {
        string v = q.front();
        // cout << v << endl;
        q.pop();

        for (int i = 0; i < v.size(); ++i)
        {
            string ss = v;
            ss.erase(i, 1);

            if (st.find(ss) == st.end() && st.size() + 1 <= k)
            {
                q.push(ss);
                st.insert(ss);
                rj += n - ss.size();
            }
        }
    }

    // for (auto i : st)
    //     cout << i << endl;

    // cout << st.size() << endl;

    if (st.size() < k)
        cout << -1 << endl;
    else
        cout << rj << endl;

    return 0;
}
