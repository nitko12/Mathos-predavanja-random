#include <iostream>

typedef long long ll;
using namespace std;

ll mod = (1e9 + 7);

int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 5; n / i >= 1; i *= 5)
        res += n / i;
    cout << res << endl;

    return 0;
}
