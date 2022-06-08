#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    auto p = tuple{3, "Ivan", 2};
    int x;
    string s;
    int y;
    tie(x, s, y) = p;
}
