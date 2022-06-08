#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int t, c;
    while (cin >> t, t)
    {
        while (1)
        {
            stack<int> s;
            int j = 0;

            for (int i = 0; i < t; ++i)
            {
                cin >> c;

                // cout << c << endl;

                if (c == 0)
                    break;

                while (j < t && j != c)
                {
                    if (s.size() > 0 && s.top() == c)
                        break;
                    ++j;
                    s.push(j);
                }
                if (s.top() == c)
                    s.pop();
            }
            if (c == 0)
                break;

            cout << (s.empty() ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}