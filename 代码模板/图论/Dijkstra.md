# Dijkstra

```c++
/*
	O(n*n)
	适用于稠密图
*/	
int g[N][N]; //初始化为inf
int dis[N];
bool st[N];
int dijkstra(int u, int v) //求点u到点v的最短路
{
    memset(dis, 0x3f, sizeof dis);
    dis[u] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        st[t] = 1;
        for (int j = 1; j <= n; j++)
            if (g[t][j] != 0x3f3f3f3f)
                dis[j] = min(dis[j], dis[t] + g[t][j]);
    }
    if (dis[v] == 0x3f3f3f3f)
        return -1;
    return dis[v];
}
```

