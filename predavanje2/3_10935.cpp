#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        deque<int> q;
        for (int i = 1; i <= n; ++i)
            q.push_back(i);

        cout << "Discarded cards:";

        int i = 0;
        while (q.size() > 1)
        {
            int t = q.front();
            q.pop_front();

            if (i++ == 0)
                cout << " " << t;
            else
                cout << ", " << t;

            t = q.front();
            q.pop_front();

            q.push_back(t);
        }
        cout << endl;

        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}