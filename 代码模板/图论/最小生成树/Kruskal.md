# Kruskal

```c++
/*
    稀疏图
*/
struct node
{
    int a, b, w;
    bool operator<(const node &x) const
    {
        return w < x.w;
    }
} e[N];
int kruskal()
{
    sort(e, e + m); //将每条边按权值升序
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = e[i].a, b = e[i].b, w = e[i].w;
        a = find(a), b = find(b); //并查集
        if (a != b)
        {
            p[a] = b,
            res += w; //最小生成树权重之和
            cnt++;    //记录集合中有多少条边
        }
    }
    if (cnt < n - 1) //图不连通
        return INT_MIN;
    return res;
}
```

