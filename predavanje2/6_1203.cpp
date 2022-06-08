#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        q;

    string s;
    int a, b;
    while (cin >> s)
    {
        if (s == "Register")
        {
            cin >> a >> b;

            q.push(make_tuple(b, a, b));
        }
        else
        {
            int t1;
            cin >> t1;

            for (int i = 0; i < t1; ++i)
            {
                int a = get<0>(q.top()),
                    c = get<1>(q.top()),
                    b = get<2>(q.top());

                q.pop();

                cout << c << endl;

                q.push({a + b, c, b});
            }
        }
    }

    return 0;
}
