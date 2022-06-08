#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    tuple<int, string, int, int> p = {3, "Ivan", 2, 6};
    auto [x, s, y, w] = p;
    cout << x << " " << s << " " << y << " " << w << endl;
}
