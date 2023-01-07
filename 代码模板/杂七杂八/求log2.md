# 求log2

```c++
int Log2[N];
void getlog2()
{
    Log2[0] = -1;
    for (int i = 1; i <= N; i++)
        Log2[i] = Log2[i >> 1] + 1;
}
```

