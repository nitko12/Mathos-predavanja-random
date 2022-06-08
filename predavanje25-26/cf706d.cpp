#include <iostream>
#include <cstring>
using namespace std;

#define int long long
int q, a[200005];

int trie[6000005][2], sum[6000005], cnt = 0;

void add(int x, int val)
{
    int node = 0;
    sum[node] += val;
    for (int i = 31; i >= 0; --i)
    {
        int y = !!(x & (1 << i));

        if (trie[node][y] == -1)
        {
            trie[node][y] = ++cnt;
        }
        node = trie[node][y];
        sum[node] += val;
    }
}

int query(int x)
{
    int node = 0, rj = 0;

    for (int i = 31; i >= 0; --i)
    {
        int y = !!(x & (1 << i));

        if (trie[node][!y] == -1 || sum[trie[node][!y]] == 0)
        {
            node = trie[node][y];
        }
        else
        {
            rj += (1 << i);
            node = trie[node][!y];
        }
    }

    return rj;
}

signed main()
{
    memset(trie, -1, sizeof trie);
    cin >> q;

    add(0, 1);

    while (q--)
    {
        char c;
        int x;

        cin >> c >> x;

        if (c == '+')
        {
            add(x, 1);
        }
        else if (c == '-')
        {
            add(x, -1);
        }
        else if (c == '?')
        {
            cout << query(x) << endl;
        }
    }

    return 0;
}