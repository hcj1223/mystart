#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int check(int l, int r)
{
    int x = 0;
    for (int i = l; i <= r; i++)
        x += s[i] - '0';
    if (x == 0)
        return 0;
    if (x == r - l + 1)
        return 1;
    return 2;
}
void dfs(int l, int r)
{
    if (l >= r)
    {
        cout << (s[l] == '0' ? "B" : "I");
        return;
    }
    int res = check(l, r), mid = (l + r) / 2;
    dfs(l, mid), dfs(mid + 1, r);
    if (res == 0)
        cout << "B";
    else if (res == 1)
        cout << "I";
    else
        cout << "F";
}
int main()
{
    cin >> n >> s;
    int m = pow(2, n) - 1;
    dfs(0, m);
    return 0;
}