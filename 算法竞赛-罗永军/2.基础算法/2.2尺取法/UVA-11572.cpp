#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int t, n;
int a[N], f[N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int res = 1;
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j <= n && f[a[j]] == 0)
            f[a[j++]] = 1;
        f[a[i]] = 0;
        res = max(res, j - i);
    }
    cout << res << endl;
}
int main()
{   
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}