#include <iostream>
#include <map>
using namespace std;

int main()
{
    string a, b;
    map<string, string> m;

    while (cin.peek() != '\n')
    {
        cin >> a >> b;
        cin.get();

        m[b] = a;
    }

    while (cin >> a)
    {
        if (m[a] != "")
            cout << m[a] << endl;
        else
            cout << "eh" << endl;
    }
    return 0;
}
