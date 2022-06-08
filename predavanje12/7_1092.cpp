#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> a, b;
    cin >> n;
    if (n % 4 == 0)
    {
        for (int i = 0; i < n / 2; ++i)
        {
            auto &t = (i & 1 ? a : b);
            t.push_back(i + 1);
            t.push_back(n - i);
        }
    }
    else if (n % 4 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    else if (n % 4 == 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);
        int i = 4, j = n, c = 0;
        while (i < j)
        {
            auto &t = (c++ & 1 ? b : a);
            t.push_back(i++);
            t.push_back(j--);
        }
    }
    cout << "YES" << endl
         << a.size() << endl;
    for (auto i : a)
        cout << i << " ";
    cout << endl
         << b.size() << endl;
    for (auto i : b)
        cout << i << " ";
    return 0;
}
