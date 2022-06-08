#include <iostream>

using namespace std;

int f(int x)
{
    // 0 ili 1
}

int main()
{
    int lo, hi;

    //           o
    // 0 0 0 0 0 1 1 1 1 1
    while (hi - lo < 0.0000000001)
    {
        int mid = (lo + hi) / 2; // pod
        if (f(mid))
            hi = mid;
        else
            lo = mid + 0.0000000001;
    }

    //         o
    // 1 1 1 1 1 0 0 0 0 0 0
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2; // strop
        if (f(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    return lo;
}