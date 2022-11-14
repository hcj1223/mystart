# Kruskal

```c++
int p[N];
struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edges[N];
//并查集
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

//按权重从小到大排序
sort(edges, edges + m);
for (int i = 1; i <= n; i++)
    p[i] = i;
int res = 0, cnt = 0; // res存储最小生成树所有树边的权重之和，cnt存储加入边的个数
//枚举所有边
for (int i = 0; i < m; i++)
{
    int a = edges[i].a, b = edges[i].b, w = edges[i].w;
    a = find(a), b = find(b);
    if (a != b) // a和b不连通
    {
        p[a] = b;
        res += w;
        cnt++;
    }
}
if (cnt < n - 1) //树不连通
```
