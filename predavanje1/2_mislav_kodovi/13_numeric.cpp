#include <numeric>
#include <iostream>
using namespace std;

int main()
{
    int Q[6];
    iota(Q, Q + 6, 1);

    for (int i = 0; i < 6; ++i)
        cout << Q[i] << " ";
    cout << endl;

    cout << accumulate(Q, Q + 6, 0) << endl;
    int acc = accumulate(Q, Q + 6, 1, [](int a, int b)
                         { return a * b; });
    cout << acc;
}
