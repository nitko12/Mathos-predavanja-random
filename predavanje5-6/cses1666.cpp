#include <iostream>
#include <vector>
using namespace std;

int n, m, v[100005];
vector<int> g[100005];

void dfs(int i)
{
    v[i] = 1;
    for (int j : g[i])
        if (!v[j])
            dfs(j);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> rj;
    for (int i = 1; i <= n; ++i)
    {
        if (!v[i])
        {
            rj.push_back(i);
            dfs(i);
        }
    }

    cout << rj.size() - 1 << endl;
    for (int i = 0; i < rj.size() - 1; ++i)
        cout << rj[i] << " " << rj[i + 1] << endl;

    return 0;
}
