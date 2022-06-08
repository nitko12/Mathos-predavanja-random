#include <iostream>
using namespace std;

//               0  1  2  3  4  5
const int a[] = {0, 0, 1, 0, -1, 0};
const int n = sizeof a / sizeof a[0] - 1;
int b[sizeof a / sizeof a[0]];

int main()
{
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 1; i <= n; ++i)
        b[i] = a[i] + b[i - 1];

    for (int i = 1; i <= n; ++i)
        cout << b[i] << " ";
    cout << endl;

    cout << b[4] - b[1] << endl; // suma od [2 do 4]
    return 0;
}