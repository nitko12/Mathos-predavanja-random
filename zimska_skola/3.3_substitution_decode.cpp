#include <iostream>
#include <map>
using namespace std;

map<string, string> m;

int main()
{
    for (int i = 0; i < 26; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;

        m[c] = a;
    }
    cin.ignore();

    string s;
    getline(cin, s);

    for (char c : s)
    {
        if (m.find(string(1, c)) != m.end())
            cout << m[string(1, c)];
        else
            cout << c;
    }
    cout << endl;

    return 0;
}
