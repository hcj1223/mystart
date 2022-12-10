# SG函数

```c++
int s[N], f[M];
memset(f, -1, sizeof f);
int sg(int x)
{
    if (f[x] != -1) // 记忆化搜索，使每个状态只需计算一次
        return f[x];
    unordered_set<int> S;
    for (int i = 0; i < n; i++)
        if (x >= s[i]) //能走到下一步
            S.insert(sg(x - s[i]));
    for (int i = 0;; i++) // 求 mex(S) 的值
        if (!S.count(i))
            return f[x] = i;
}
```

