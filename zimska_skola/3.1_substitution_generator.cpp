#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

int main()
{
    char a[26];
    for (int i = 0; i < 26; ++i)
        a[i] = 'a' + i;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(a, a + 26, default_random_engine(seed));

    for (int i = 0; i < 26; ++i)
        cout << (char)('a' + i) << " -> " << a[i] << endl;

    return 0;
}
