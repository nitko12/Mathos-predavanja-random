void update(int x, int val)
{
    int now = root;
    cnt[now] += val;
    for (int i = 29; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (tree[now][c] == 0)
        {
            cur++;
            tree[now][c] = cur;
        }
        now = tree[now][c];
        cnt[now] += val;
    }
}

void query(int x)
{
    int now = root;
    int ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (tree[now][1 ^ c] == 0 || cnt[tree[now][1 ^ c]] == 0)
        {
            // ans = ans;
        }
        else
        {
            ans += (1 << i);
            c ^= 1;
        }
        now = tree[now][c];
    }
    printf("%d\n", ans);
}