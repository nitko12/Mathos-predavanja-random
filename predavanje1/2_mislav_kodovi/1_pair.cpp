#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ispis(pair<int, string> p)
{
    cout << p.second << ' ' << p.first << '\n';
}

int main()
{
    pair<pair<int, int>, double> p;

    p.first = {1, 2};
    p.second = 2;

    auto [x, y] = p;

    cout << x << endl;
}
