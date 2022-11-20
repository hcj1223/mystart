# 堆优化Dijkstra

```c++
/*
	O(mlogn)
	稀疏图
*/
typedef pair<int, int> pll;
int h[N], e[N], ne[N], w[N], idx;
int dis[N];
bool st[N];
int dijkstra(int u, int v) //求点u到点v的最短路
{
    memset(dis, 0x3f, sizeof dis);
    dis[u] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q; //前一个是该点到点u的最短路，后一个是该点的编号
    q.push({0, u});
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int d = t.first, x = t.second;
        if (st[x])
            continue;
        st[x] = 1;
        for (int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > d + w[i])
            {
                dis[j] = d + w[i];
                q.push({dis[j], j});
            }
        }
    }
    if (dis[v] == 0x3f3f3f3f)
        return -1;
    return dis[v];
}
```

