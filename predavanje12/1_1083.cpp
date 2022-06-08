#include <iostream>
using namespace std;

int n;
bool a[200001];

int main()
{
    int a;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a, ::a[a] = 1;
    for (int i = 1; i <= n; ++i)
        if (!::a[i])
        {
            cout << i << endl;
            return 0;
        }

    return 0;
}