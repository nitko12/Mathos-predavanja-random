#include <iostream>
#include <algorithm>
using namespace std;

int A[10];

void predicate()
{
    if (all_of(A, A + 10, [](int x)
               { return x != 0; }))
        cout << "all != 0\n";
    if (none_of(A, A + 10, [](int x)
                { return x % 7 == 0; }))
        cout << "none % 7 == 0\n";
    if (any_of(A, A + 10, [](int x)
               { return x < 0; }))
        cout << "any < 0\n";

    cout << count(A, A + 10, 5) << '\n';
    cout << count_if(A, A + 10, [](int x)
                     { return x % 2 == 0; })
         << '\n';
}

void find()
{
    int *p = find(A, A + 10, 5);
    if (p != A + 10)
        *p = 10;

    int *q = find_if(A, A + 10, [](int x)
                     { return x % 2 == 0; });
    cout << q - A << '\n';
    int *s = find_if_not(A, A + 10, [](int x)
                         { return x > 0; });
}

void modify()
{
    fill(A, A + 10, 0);
    A[5] = 1;
    A[8] = -1;
    // 0 0 0 0 0 1 0 0 -1 0
    int n = distance(A, unique(A, A + 10));
    // 0 1 0 -1 0 - - - - -
    int m = distance(A, unique(A, A + n, [](int a, int b)
                               { return abs(a) == abs(b); }));
    sort(A, A + 10, [](int a, int b)
         { return abs(a) < abs(b); });
    stable_sort(A, A + 10, [](int a, int b)
                { return abs(a) < abs(b); });
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cin >> A[i];

    predicate();
    find();
    modify();
}
