#include <iostream>
using namespace std;
const int N = 100010, inf = 0x3f3f3f3f;
int t, n, a[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = -inf, st = 1, ed = 1;
    int sum = 0, p = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > res)
            res = sum, st = p, ed = i;
        if (sum < 0)
            sum = 0, p = i + 1;
    }
    cout << res << " " << st << " " << ed << endl;
}
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << endl;
        solve();
        if (i != t)
            cout << endl;
    }
    return 0;
}