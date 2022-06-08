#include <iostream>
#include <deque>
using namespace std;

int freq[30];
string s;

int main()
{
    cin >> s;

    for (int i = 0; i < s.size(); ++i)
        ++freq[s[i] - 'A'];

    int cnt = 0;
    for (int i = 0; i < 30; ++i)
        cnt += freq[i] % 2;

    if (cnt >= 2)
        return cout << "NO SOLUTION" << endl, 0;

    deque<char> d;

    for (int i = 0; i < 30; ++i)
        if (freq[i] % 2)
        {
            d.push_back('A' + i);
            --freq[i];
        }

    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < freq[i] / 2; ++j)
        {
            d.push_front('A' + i);
            d.push_back('A' + i);
        }
    }

    cout << string(d.begin(), d.end()) << endl;

    return 0;
}
