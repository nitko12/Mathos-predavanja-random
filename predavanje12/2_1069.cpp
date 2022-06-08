#include <iostream>
using namespace std;

int main()
{
    int mx = 0, si = 0;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[si])
            continue;
        else
        {
            mx = max(mx, i - si);
            si = i;
        }
    }
    mx = max(mx, (int)s.size() - si);
    cout << mx << endl;

    return 0;
}
