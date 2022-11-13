

# KMP

## 1.下标从 1 开始

```c++
void getnext(char t[], int ne[])
{
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && t[j + 1] != t[i])
            j = ne[j];
        if (t[j + 1] == t[i])
            j++;
        ne[i] = j;
    }
}

int findpos(char s[], char t[], int ne[])
{
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && t[j + 1] != s[i])
            j = ne[j];
        if (t[j + 1] == s[i])
            j++;
        if (j == n) //匹配成功
        {
            j = ne[j];
            return i - n + 1; //出现位置的起始下标
        }
    }
    return -1;
}
```

## 2.下标从 0 开始

```c++
void getnext(char t[], int ne[])
{
    ne[0] = -1;
    for (int i = 1, j = -1; t[i]; i++)
    {
        while (j != -1 && t[i - 1] != t[j])
            j = ne[j];
        j++;

        //改进版
        if (t[i] == t[j])
            ne[i] = ne[j];
        else
            ne[i] = j;
    }
}

int findpos(char s[], char t[], int ne[])
{
    int i = 0, j = 0;
    while (i < strlen(s) && j < strlen(t))
    {
        if (s[i] == t[j])
            i++, j++;
        else
        {
            j = ne[j];
            if (j == -1)
                i++, j = 0;
        }
    }
    if (j >= strlen(t))
        return i - j;
    return -1;
}
```

