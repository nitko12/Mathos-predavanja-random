#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; ++i)
    {
        string ime;
        cin >> ime;
        s.insert(ime);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string ime;
        cin >> ime;

        if (s.find(ime) != s.end())
            cout
                << "DA\n";
        else
            cout << "NE\n";
    }
}
