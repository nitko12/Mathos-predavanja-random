#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int q;
    cin >> q;
    queue<int> red;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            red.push(x);
        }
        else
        {
            cout << red.front() << "\n";
            red.pop();
        }
    }

    return 0;
}
