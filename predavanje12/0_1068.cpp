#include <iostream>
using namespace std;
long long int n;

void run(long long int a)
{
    cout << a << " ";
    if (a == 1)
        return;
    if (a & 1)
        run(a * 3 + 1);
    else
        run(a >> 1);
}

int main()
{
    cin >> n;
    run(n);

    return 0;
}
