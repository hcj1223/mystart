# 进制转化

## 1.其他进制转十进制

```c++
int turn(string s, int b)
{
    int res = 0;
    for (auto c : s)
        res = res * b + c - '0';
    return res;
}
```

## 2.十进制转其他进制

```c++
char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
void turndata(int n, int a)
{
    int x[17], i, j, k = 0;
    if (n < 0)
        cout << '-';
    j = abs(n);
    do
    {
        k++;
        i = j % a;
        j /= a;
        x[k] = i;
    } while (j != 0);
    for (int h = k; h >= 1; --h)
    {
        if (x[h] < 10)
            cout << x[h];
        else
            cout << ch[x[h] - 10];
    }
    cout << ' ';
}
```

# 任意输入数字

```c++
vector<int> nums;
int k = 0;
while (cin >> k)
{
    nums.push_back(k);
    if (cin.get() == '\n')
        break;
}
```

# 四舍五入

```c++
int round_double(double number)
{
    return (number > 0.0) ? (number + 0.5) : (number - 0.5);
}
```

# 优化整数读入

```c++
void read(int &x)
{
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar())
        ;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
}
```

