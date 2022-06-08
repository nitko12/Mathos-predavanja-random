#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> m;

    for (int i = 0; i < n; ++i)
    {
        string ime;
        cin >> ime;
        m[ime]++;
    }

    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    pair<string, int> p;
    for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i)
        if (i->second > p.second)
            p = *i;

    cout << p.first << endl;
}
