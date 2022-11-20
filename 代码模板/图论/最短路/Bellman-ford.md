# Bellman Ford

```c++
/*
    O(n*m)
*/
struct node
{
    int a, b, w;
} e[M];
int dis[N], backup[N];
int bellman_ford(int u, int v)
{
    memset(dis, 0x3f, sizeof dis);
    dis[u] = 0;
    for (int i = 0; i < k; i++) //有经过边数限制，无限制则k = n
    {
        memcpy(backup, dis, sizeof dis); //备份dis[]，避免串联
        for (int j = 0; j < m; j++)
        {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }
    if (dis[v] > 0x3f3f3f3f - N * M)
        return INT_MIN;
    return dis[n];
}
```

