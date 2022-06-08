#include <queue>
#include <iostream>
using namespace std;

void pqueue_int()
{
    priority_queue<int> Q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;
        Q.push(s);
    }
    while (!Q.empty())
    {
        cout << Q.top() << ' ';
        Q.pop();
    }
}

struct cmp
{
    // ima li a manji prioritet od b?
    bool operator()(string &a, string &b)
    {
        if (a.size() == b.size())
            return a > b;
        return a.size() > b.size();
    }
};

void pqueue_str()
{
    priority_queue<string, vector<string>, cmp> Q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        Q.push(s);
    }
    while (!Q.empty())
    {
        cout << Q.top() << ' ';
        Q.pop();
    }
}

int main()
{
    // pqueue_int();
    pqueue_str();
}
