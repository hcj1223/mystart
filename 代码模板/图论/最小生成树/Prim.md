# Prim

```c++
/*
适用于稠密图
*/
int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        //找到当前集合外距离最小的点
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (i && dist[t] == INF) //图不连通
            return INF;
        if (i)
            res += dist[t];
        st[t] = true;
        //用t更新其他点到集合的距离
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
```

