#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, p;
        cin >> n >> p;

        queue<pair<int, bool>> q;
        int pr[10] = {0};
        for (int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            ++pr[t];
            q.push({t, p == i});
        }

        for (int i = 0;;)
        {
            int f = 0;
            for (int j = q.front().first + 1; j < 10; ++j)
                if (pr[j])
                    f = 1;

            if (f)
            {
                q.push(q.front());
                q.pop();

                continue;
            }

            if (q.front().second)
            {
                cout << i + 1 << endl;
                break;
            }

            --pr[q.front().first];
            q.pop();
            ++i;
        }
    }

    return 0;
}