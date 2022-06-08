#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    vector<int> A = {4, 1, 6, 2, 8, 0, -2, 2};
    auto cmp = [](int a, int b)
    {
        return abs(a) < abs(b);
    };
    // 0 1 2 -2 2 4 6 8
    stable_sort(A.begin(), A.end(), cmp);

    // cout << *lower_bound(A.begin(), A.end(), 2, cmp) << endl;

    // lower_bound
    // upper_bound
    // equal_range
    vector<int>::iterator lb, ub;
    tie(lb, ub) = equal_range(A.begin(), A.end(), 2, cmp);
    for (auto it = lb; it != ub; ++it)
        cout << *it << ' ';
}
