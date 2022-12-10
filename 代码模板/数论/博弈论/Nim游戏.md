# Nim游戏

###### *先手必胜状态*：可以达到某个必败状态

###### *先手必败状态*：达不到任何一个必败状态

### 1.朴素-Nim

![朴素nim](https://user-images.githubusercontent.com/95573252/206850131-1af67a1e-77d3-4303-90c5-794eb9f3b41e.png)

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

![台阶nim](https://user-images.githubusercontent.com/95573252/206850150-bee3d524-5d7f-4c6c-89b0-062d555d2692.png)

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

![集合nim](https://user-images.githubusercontent.com/95573252/206850168-f3887e32-dd33-4fe4-a764-5de59d7d999c.png)

### 4.拆分-Nim

![拆分nim](https://user-images.githubusercontent.com/95573252/206850185-976ab657-d8e7-4420-901f-af9f579662b5.png)

