#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ft(200005);

int rsq(int b)
{
    int sum = 0;
    for (; b; b -= (b & (-b)))
        sum += ft[b];
    return sum;
}

int rsq(int a, int b)
{
    return rsq(b) - rsq(a - 1);
}

int q(int x)
{
    return rsq(x) - rsq(x - 1);
}

void adjust(int k, int v)
{
    for (; k < ft.size(); k += (k & (-k)))
        ft[k] += v;
}

int n;
pair<int, int> a[100005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        a[i] = {x, y};
    }

    sort(a, a + n, [](const auto a, const auto b)
         { return a.first * b.second > b.first * a.second; });

    // for (int i = 0; i < n; ++i)
    //     cout << a[i].first << " " << a[i].second << endl;

    for (int i = 0; i < n; ++i)
    {
        adjust();
    }

    return 0;
}