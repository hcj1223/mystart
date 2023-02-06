# 输出与(I,J)同对角线的坐标

```c++
for (int m = 1; m <= N; m++)
    for (int n = 1; n <= N; n++)
        if ((m - I) == (n - J))
            cout << "(" << m << "," << n << ") ";
for (int m = N; m >= 1; m--)
    for (int n = N; n >= 1; n--)
        if ((m - I) == -(n - J))
            cout << "(" << m << "," << n << ") ";
```

