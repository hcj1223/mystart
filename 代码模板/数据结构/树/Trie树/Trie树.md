# Trie树

```c++
int child[N][26], cnt[N], idx;
//下标是0的点既是根节点又是空节点
//"26"表示一个节点最多有26个儿子
// cnt[]存储以该点结尾的单词数量

//插入一个字符串
void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a'; //字符串全是小写字母
        if (!child[p][u])
            child[p][u] = ++idx;
        p = child[p][u];
    }
    cnt[p]++;
}
//询问字符串在集合中出现的次数
int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!child[p][u])
            return 0;
        p = child[p][u];
    }
    return cnt[p];
}
```

