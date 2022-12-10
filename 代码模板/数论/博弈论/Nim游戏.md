# Nim游戏

###### *先手必胜状态*：可以达到某个必败状态

###### *先手必败状态*：达不到任何一个必败状态

### 1.朴素-Nim

```c++
int res = 0;
for (int i = 1; i <= n; i++)
{
    int x;
    cin >> x;
    res ^= x;
}
if (res)
    cout << "Yes"; //先手必胜
else
    cout << "No";  //先手必败
```

### 2.台阶-Nim

```c++
int res = 0;
for (int i = 1; i <= n; i++)
{
    int x;
    cin >> x;
    if (i & 1)
        res ^= x;
}
if (res)
    cout << "Yes";
else
    cout << "No";
```

### 3.集合-Nim

```c++
int res = 0;
for (int i = 0; i < m; i++)
{
    int x;
    cin >> x;
    res ^= sg(x);
}
if (res)
    cout << "Yes";
else
    cout << "No";
```

### 4.拆分-Nim

```c++
int res = 0;
for (int i = 0; i < n; i++)
{
    int x;
    cin >> x;
    res ^= sg(x);
}
if (res)
    cout << "Yes";
else
    cout << "No";
```

