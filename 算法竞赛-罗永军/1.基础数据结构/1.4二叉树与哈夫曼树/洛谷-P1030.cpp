#include <bits/stdc++.h>
using namespace std;
string in, post;
int lson[10], rson[10];
int buildTree(int l1, int l2, int m)
{
    if (m <= 0)
        return 0;
    int root = post[l2 + m - 1] - 'A' + 1;
    int p = 0;
    while (in[l1 + p] - 'A' + 1 != root)
        p++;
    lson[root] = buildTree(l1, l2, p);
    rson[root] = buildTree(l1 + p + 1, l2 + p, m - p - 1);
    return root;
}
void dfs(int u)
{
    if (u == 0)
        return;
    char ch = 'A' + u - 1;
    cout << ch;
    dfs(lson[u]), dfs(rson[u]);
}
int main()
{
    cin >> in >> post;
    int len = post.size();
    buildTree(0, 0, len);
    int root = post[len - 1] - 'A' + 1;
    dfs(root);
    return 0;
}