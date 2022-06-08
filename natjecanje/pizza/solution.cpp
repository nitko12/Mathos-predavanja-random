#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double r1, r2;
    int n;

    cin >> r1 >> r2 >> n;

    cout << (n * r1 * r1 * M_PI > r2 * r2 * M_PI ? "DA" : "NE") << endl;

    return 0;
}
