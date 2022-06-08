#include <iostream>
using namespace std;

int f(int x)
{
    if (x == 0)
        return 1;
    return x * f(x - 1);
}

int main()
{
    cout << f(5) << endl;
    return 0;
}
