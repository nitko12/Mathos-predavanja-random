    #include <iostream>
    #include <queue>
    #include <utility>
    using namespace std;
     
    string s[55];
    int h, w, a[55][55], v[55][55];
     
    int main()
    {
        cin >> h >> w;
        int b = 0;
        for (int i = 0; i < h; ++i)
            cin >> s[i];
     
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                v[i][j] = -1;
     
        queue<pair<int, int>> q;
     
        q.push({0, 0});
        v[0][0] = 0;
     
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int dx[] = {-1, 0, 0, 1},
                dy[] = {0, 1, -1, 0};
            for (int k = 0; k < 4; ++k)
            {
                int xx = t.first + dx[k],
                    yy = t.second + dy[k];
                if (0 <= xx && xx < w && 0 <= yy && yy < h && s[yy][xx] == '.' && v[yy][xx] == -1)
                {
                    v[yy][xx] = v[t.second][t.first] + 1;
                    q.push({xx, yy});
                }
            }
        }
     
        if (v[h - 1][w - 1] == -1)
            return cout << -1 << endl, 0;
     
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
                b += (s[i][j] == '#');
        }
     
        cout << h * w - b - v[h - 1][w - 1] - 1 << endl;
        return 0;
    }