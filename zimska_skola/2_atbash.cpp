#include <iostream>
#include <cctype>
using namespace std;

int shift;
string s;

string encode(const string &s)
{
    string r;

    for (auto c : s)
    {
        if (islower(c))
        {
            r += (char)(25 - (c - 'a') + 'a');
            continue;
        }

        if (isupper(c))
        {
            r += (char)(25 - (c - 'A') + 'A');
            continue;
        }

        r += c;
    }

    return r;
}

int main()
{
    getline(cin, s);

    cout << encode(s) << endl;

    return 0;
}
