# SPFA

```c++
bool st[N]; //存贮该元素是否在队列中
int spfa(int u, int v)
{
    memset(dis, 0x3f, sizeof h);
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    st[u] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    if (dis[v] == 0x3f3f3f3f)
        return INT_MIN;
    return dis[v];
}
```

