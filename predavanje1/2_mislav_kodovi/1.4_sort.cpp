#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {9, -5, 6, 5, 8, -8, 5, 5, -5, -5};

    // for (int i = 0; i < v.size(); ++i)
    // {
    //     int mni = i;
    //     for (int j = i + 1; j < v.size(); ++j)
    //         if (v[mni] < v[j])
    //             mni = j;

    //     int tmp = v[mni];
    //     v[mni] = v[i];
    //     v[i] = tmp;
    // }

    sort(v.begin(), v.end(), [](int x, int y)
         {
        if (abs(x) != abs(y))
            return abs(x) < abs(y);
        return x < y; });

    for (int x : v)
        cout << x << ' ';
}
