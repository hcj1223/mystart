#include <iostream>
using namespace std;
const int N = 100010;
int t, n, s;
int a[N];
int solve()
{
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), a[i] += a[i - 1];
    int res = n + 1; 
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j <= n && a[j] - a[i - 1] < s)
            j++;
        if (j <= n)
            res = min(res, j - i + 1);
    }
    return res > n ? 0 : res; 
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &s);
        int res = solve();
        printf("%d\n", res);
    }
    return 0;
}