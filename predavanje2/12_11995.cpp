#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        bool fq = 0, fs = 0, fpq = 0;

        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;

            if (a == 1)
            {
                q.push(b);
                s.push(b);
                pq.push(b);
            }
            else
            {
                if (q.empty())
                {
                    fq = fs = fpq = 1;
                    continue;
                }

                if (q.front() != b)
                    fq = 1;
                if (s.top() != b)
                    fs = 1;
                if (pq.top() != b)
                    fpq = 1;

                q.pop();
                s.pop();
                pq.pop();
            }
        }

        if (!fq && fs && fpq)
            cout << "queue" << endl;
        else if (fq && !fs && fpq)
            cout << "stack" << endl;
        else if (fq && fs && !fpq)
            cout << "priority queue" << endl;
        else if (fq && fs && fpq)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;
    }

    return 0;
}