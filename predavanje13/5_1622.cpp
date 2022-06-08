#include <bits/stdc++.h>
using namespace std;

string s;
set<string> rj;

int main()
{
    cin >> s;
    sort(s.begin(), s.end());

    do
    {
        rj.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << rj.size() << endl;
    for (string i : rj)
        cout << i << endl;

    return 0;
}