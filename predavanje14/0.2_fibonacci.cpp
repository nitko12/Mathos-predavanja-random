#include <iostream>
using namespace std;

int f(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return f(x - 1) + f(x - 2);
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << f(i) << endl;
    return 0;
}
