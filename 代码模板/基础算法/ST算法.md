# ST算法

```c++
void init()
{
    for (int i = 1; i <= n; i++)
        dp[i][0] = a[i];
    int p = log2(n); // 可倍增区间的最大次方
    for (int k = 1; k <= p; k++)
        for (int s = 1; s + (1 << k) <= n + 1; s++)
            dp[s][k] = min(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
}
int query(int L, int R)
{
    int k = log2(R - L + 1);                       // 将区间[L, R]分成两个长度为 k 的区间
    return min(dp[L][k], dp[R - (1 << k) + 1][k]); // 区间最小值
                                                   // dp[s][k]表示左端点为 s 的长度为 2^k 的区间的最值
}
```

