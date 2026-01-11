#include <bits/stdc++.h>
using namespace std;
int n;
int root;
int lson[30], rson[30];
void dfs(int u)
{
    if (u <= 0)
        return;
    char r = 'a' + u - 1;
    cout << r;
    dfs(lson[u]), dfs(rson[u]);
}
int main()
{
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int r = str[0] - 'a' + 1;
        if (root == 0)
            root = r;
        if (str[1] != '*')
            lson[r] = str[1] - 'a' + 1;
        if (str[2] != '*')
            rson[r] = str[2] - 'a' + 1;
    }
    dfs(root);
    return 0;
}