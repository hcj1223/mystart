# Kruskal

```c++
/*
适用于稀疏图
*/
struct node
{
    int a, b, w;
    bool operator<(const node &W) const
    {
        return w < W.w;
    }
} e[N];

//按权重从小到大排序
sort(e, e + m);
int res = 0, cnt = 0; // res存储最小生成树所有树边的权重之和，cnt存储加入边的个数
for (int i = 0; i < m; i++)
{
    int a = e[i].a, b = e[i].b, w = e[i].w;
    a = find(a), b = find(b); //并查集
    if (a != b)               // a和b不连通
    {
        p[a] = b;
        res += w;
        cnt++;
    }
}
if (cnt < n - 1) //树不连通
```

