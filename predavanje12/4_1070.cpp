#include <iostream>
#include <algorithm>
using namespace std;

int a[1000000], n;

bool test()
{
    for (int i = 1; i < n; ++i)
        if (abs(a[i] - a[i - 1]) == 1)
            return 0;
    return 1;
}

int main()
{
    int b = 3;
    cin >> n;
    if (n == 1)
        (cout << "1" << endl, 0);
    if (n <= 3)
        return (cout << "NO SOLUTION" << endl, 0);
    for (int i = 1; i <= n; ++i)
        a[i - 1] = i;
    do
    {
        random_shuffle(a, a + n);
    } while (!test());
    for (int i = 0; i < n; ++i)
        cout << ::a[i] << " ";
    cout << endl;

    return 0;
}
