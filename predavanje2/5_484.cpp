#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> v;
    map<int, int> m;
    int t;

    while (cin >> t)
    {
        v.push_back(t);
        ++m[t];
    }

    for (int i : v)
    {
        if (m[i])
            cout << i << " " << m[i] << endl;

        m[i] = 0;
    }

    return 0;
}
