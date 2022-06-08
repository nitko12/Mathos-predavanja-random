#include <iostream>
using namespace std;

int l[70];
string s;

int main()
{
    for (int i = 0; i < 64; ++i)
        for (int j = 0; j < 64; ++j)
            ++l[i & j];

    cin >> s;

    int rj = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if ('0' <= s[i] && s[i] <= '9')
            rj = (1ll * rj * l[s[i] - '0']) % (int)(1e9 + 7);
        else if ('A' <= s[i] && s[i] <= 'Z')
            rj = (1ll * rj * l[s[i] - 'A' + 10]) % (int)(1e9 + 7);
        else if ('a' <= s[i] && s[i] <= 'z')
            rj = (1ll * rj * l[s[i] - 'a' + 36]) % (int)(1e9 + 7);
        else if (s[i] == '-')
            rj = (1ll * rj * l[62]) % (int)(1e9 + 7);
        else if (s[i] == '_')
            rj = (1ll * rj * l[63]) % (int)(1e9 + 7);
    }

    cout << rj << endl;
}
