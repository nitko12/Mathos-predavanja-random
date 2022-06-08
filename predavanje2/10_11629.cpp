#include <iostream>
#include <map>
using namespace std;

int main()
{
    int p, g;
    cin >> p >> g;

    map<string, double> m;

    for (int i = 0; i < p; ++i)
    {
        string s;
        double p;

        cin >> s >> p;
        m[s] = p;
    }

    for (int i = 0; i < g; ++i)
    {
        string s;
        double r = 0, l = 0;

        int op;

        for (;;)
        {
            cin >> s;

            if (s == "<")
            {
                op = 0;
                break;
            }
            else if (s == ">")
            {
                op = 1;
                break;
            }
            else if (s == "<=")
            {
                op = 2;
                break;
            }
            else if (s == ">=")
            {
                op = 3;
                break;
            }
            else if (s == "=")
            {
                op = 4;
                break;
            }
            else if (s == "+")
            {
            }
            else if (m.find(s) == m.end())
            {
                l += stod(s);
            }
            else
            {
                l += m[s];
            }
        }

        while (cin.peek() != '\n')
        {
            string s;
            if (!(cin >> s))
                break;

            // cout << "aaa" << s << endl;

            if (s == "+")
            {
            }
            else if (m.find(s) == m.end())
            {

                r += stod(s);
            }
            else
            {
                r += m[s];
            }
        }

        // if (i + 1 == 96)
        //     cout << op << " " << l << " " << r << endl;

        cout << "Guess #" << i + 1 << " was ";
        switch (op)
        {
        case 0:
            cout << (l + 1e-7 < r ? "correct."
                                  : "incorrect.");
            break;
        case 1:
            cout << (l > r + 1e-7 ? "correct."
                                  : "incorrect.");
            break;
        case 2:
            cout << (l <= r + 1e-7 ? "correct."
                                   : "incorrect.");
            break;
        case 3:
            cout << (l + 1e-7 >= r ? "correct."
                                   : "incorrect.");
            break;
        case 4:
            cout << (abs(l - r) < 1e-5 ? "correct."
                                       : "incorrect.");
            break;
        default:
            break;
        }
        cout << endl;
    }

    return 0;
}
