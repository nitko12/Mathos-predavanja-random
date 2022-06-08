#include <iostream>
#include <cstring>
using namespace std;

int n, a[200005];

int child[200005 * 32][2], tick = 1;

void add(int p)
{
    int node = 0;

    for (int i = 31; i >= 0; --i)
    {
        int x = !!(p & (1 << i));

        if (child[node][x] == -1)
            child[node][x] = tick++;

        node = child[node][x];
    }
}

int query(int p)
{
    int node = 0, ans = 0;
    for (int i = 31; i >= 0; --i)
    {
        int val = !!(p & (1 << i));

        if (child[node][1 - val] != -1)
        {
            node = child[node][1 - val];
            ans += (1 << i);
        }
        else if (child[node][val] != -1)
            node = child[node][val];
    }

    return ans;
}

int main()
{
    memset(child, -1, sizeof child);
    cin >> n;

    int x = 0, mx = 0;
    add(x);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        x ^= a[i];
        add(x);
        mx = max(mx, query(x));
    }

    cout << mx << endl;

    return 0;
}