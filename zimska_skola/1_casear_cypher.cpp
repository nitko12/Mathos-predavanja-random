#include <iostream>
#include <cctype>
using namespace std;

int shift;
string s;

string encode(const string &s, int shift)
{
    string r;

    for (auto c : s)
    {
        if (islower(c))
        {
            r += (char)(((c - 'a') + shift + 26) % 26 + 'a');
            continue;
        }

        if (isupper(c))
        {
            r += (char)(((c - 'A') + shift + 26) % 26 + 'A');
            continue;
        }

        r += c;
    }

    return r;
}

int main()
{
    cin >> shift;
    cin.ignore();
    getline(cin, s);

    cout << encode(s, shift) << endl;

    return 0;
}
