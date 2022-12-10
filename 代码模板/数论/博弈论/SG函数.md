# SG函数

![sg函数](https://user-images.githubusercontent.com/95573252/206846767-533341ee-dd7d-4bc5-ac23-27b0f4e87d20.png)

```c++
int s[N], dp[M];
memset(dp, -1, sizeof dp);
int sg(int x)
{
    if (dp[x] != -1) // 记忆化搜索，使每个状态只需计算一次
        return dp[x];
    unordered_set<int> S;
    for (int i = 0; i < n; i++)
        if (x >= s[i]) //能走到下一步
            S.insert(sg(x - s[i]));
    /*
        for (int i = 0; i < x; i++)
            for (int j = 0; j <= i; j++)
                S.insert(sg(i) ^ sg(j)); // sg(i, j) = sg(i) ^ sg(j)
    */
    for (int i = 0;; i++) // 求 mex(S) 的值
        if (!S.count(i))
            return dp[x] = i;
}
```

