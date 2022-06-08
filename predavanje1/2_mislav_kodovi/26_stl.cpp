#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

using edge = tuple<int, int, int>;

int main()
{
    auto cmp = [](edge p, edge q)
    {
        auto [a1, b1, w1] = p;
        auto [a2, b2, w2] = q;
        return w1 > w2;
    };
    priority_queue<edge, vector<edge>, decltype(cmp)> Q(cmp);
    Q.push({0, 1, 3});
    Q.push({0, 2, 5});
    Q.push({0, 3, 1});
    vector<edge> V;
    while (!Q.empty())
    {
        auto [a, b, w] = Q.top();
        cout << w << endl;
        V.push_back(Q.top());
        Q.pop();
    }
    cout << endl;
    sort(V.begin(), V.end(), cmp);
    for (auto [a, b, w] : V)
        cout << w << endl;
}
