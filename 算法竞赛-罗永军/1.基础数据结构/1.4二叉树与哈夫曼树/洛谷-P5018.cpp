#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
int v[N], lson[N], rson[N];
bool isSame(int u1, int u2)
{
    if (u1 == -1 && u2 == -1)
        return 1;
    if (u1 == -1 || u2 == -1)
        return 0;
    if (v[u1] != v[u2])
        return 0;
    return isSame(lson[u1], rson[u2]) && isSame(rson[u1], lson[u2]);
}
int treeNodeNum(int u)
{
    if (u == -1)
        return 0;
    return 1 + treeNodeNum(lson[u]) + treeNodeNum(rson[u]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> lson[i] >> rson[i];
    int res = 1;
    for (int i = 1; i <= n; i++)
        if (isSame(i, i))
            res = max(res, treeNodeNum(i));
    cout << res << endl;
    return 0;
}