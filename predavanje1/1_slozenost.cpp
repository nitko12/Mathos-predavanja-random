#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int binomialCoeff(int n, int k)
{

    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int main()
{
    // O(1)
    cout << "a" << endl;

    int n = 10, c = 0;

    // O(n)
    for (int i = 0; i < n; ++i)
        ++c;

    // O(n^2)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ++c;

    // Zadatak: O(??)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            ++c;

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < i; ++j)
    //         cout << "#";
    //     cout << endl;
    // }

    // O(log n)
    for (int i = n; i > 0; i /= 2) // n >>= 1;
        ++c;

    // O(n log n)
    for (int i = 0; i < n; ++i)
        for (int j = n; j > 0; j /= 2)
            ++c;

    // Zadatak: O(n)
    for (int i = n; i > 0; i /= 2)
    {
        for (int j = 0; j < i; ++j)
            ++c;
    }

    // for (int i = n; i > 0; i /= 2)
    // {
    //     for (int j = 0; j < i; ++j)
    //         cout << "#";
    //     cout << endl;
    // }

    // Zadatak: naći sve djeljitelje broja
    // O(sqrt n)

    // int a = 30;
    // set<int> s;

    // for (int i = 1; i * i <= a; ++i)
    //     if (a % i == 0)
    //     {
    //         s.insert(i);
    //         if (i != a / i)
    //             s.insert(a / i);
    //     }

    // for (int i : s)
    //     cout << i << " ";

    // cout << endl;

    // Naivno računanje ncr-a (binomnog koeficijenta)
    // O(??)

    // n = 26;
    // int r = 3, rj = 0;
    // for (int i = 0; i < (1 << n); ++i) // i < 2^n
    // {
    //     // for (int j = 0; j < n; ++j)
    //     //     if (i & (1 << j))
    //     //         cout << 1;
    //     //     else
    //     //         cout << 0;
    //     // cout << endl;
    //     int c = 0;
    //     for (int j = 0; j < n; ++j)
    //         if (i & (1 << j))
    //             ++c;
    //     if (c == r)
    //         ++rj;
    // }
    // cout << rj << endl;

    // Fibonacci - rekurzivno vs iterativno
    // O(phi ^ n) vs O(n)
    {
        // cout << fibonacci(100) << endl;

        // n = 1000;
        // int a0 = 1, a1 = 1;
        // for (int i = 0; i < n - 1; ++i)
        // {
        //     int b = a0 + a1;
        //     a0 = a1;
        //     a1 = b;
        // }
        // cout << a1 << endl;
    }

    // Travelling salesman
    // O(n!)
    {
        srand(time(0));
        n = 12;
        int a[n][n], p[n];

        for (int i = 0; i < n; ++i)
            p[i] = i;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j)
                    a[i][j] = 0;
                else
                    a[i][j] = rand() % 100;

        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //         cout << a[i][j] << " ";
        //     cout << endl;
        // }

        int mincost = 1e9;
        do
        {
            int cost = 0;

            for (int i = 0; i < n; ++i)
                cost += a[p[i]][p[(i + 1) % n]];

            mincost = min(cost, mincost);

            // for (int i = 0; i < n; ++i)
            //     cout << p[i] << " ";
            // cout << endl;

            // cout << cost << endl;

            // for (int i = 0; i < n; ++i)
            //     cout << p[i] << " ";
            // cout << endl;

        } while (next_permutation(p, p + n));

        cout << mincost << endl;
    }

    return 0;
}
