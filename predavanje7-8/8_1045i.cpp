#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> m;
string s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;

        int a = 0;
        for (auto c : s)
            a ^= 1 << (c - 'a');

        ++m[a];
    }

    // ????

    long long rj = 0;
    for (auto [k, v] : m)
    {
        rj += (1ll * v * (v - 1)) / 2;

        for (int i = 0; i < 26; i++)
            if ((k & (1 << i)) && m.find(k ^ (1 << i)) != m.end())
                rj += 1ll * v * m[k ^ (1 << i)];
    }

    cout << rj << endl;

    return 0;
}
