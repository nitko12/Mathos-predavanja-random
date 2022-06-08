#include <iostream>
#include <set>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        set<int> sa, sb;

        for (int i = 0; i < a; ++i)
        {
            int t;
            cin >> t;

            sa.insert(t);
        }

        for (int i = 0; i < b; ++i)
        {
            int t;
            cin >> t;

            sb.insert(t);
        }

        int cnt = 0;
        for (int i : sa)
            if (sb.find(i) != sb.end())
                ++cnt;

        cout << cnt << endl;
    }

    return 0;
}
