#include <iostream>
using namespace std;

int a[200001];

int main()
{
    int n;
    long long int sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            sum += a[i - 1] - a[i], a[i] = a[i - 1];
    cout << sum << endl;

    return 0;
}
