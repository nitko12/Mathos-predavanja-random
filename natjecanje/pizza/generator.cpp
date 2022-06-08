#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for (int i = 1; i <= 100; ++i)
    {
        startTest(i);

        cout << 100. * (rnd.next(1, 1000) / 1000.) << " "
             << 100. * (rnd.next(1, 1000) / 1000.) << endl;

        cout << rnd.next(1, 100) << endl;
    }

    return 0;
}
