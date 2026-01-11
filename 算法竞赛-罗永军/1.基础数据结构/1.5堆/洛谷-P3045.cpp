#include <bits/stdc++.h>
using namespace std;
#define cjf ios ::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 50010;
struct node
{
    int p, c;
    bool operator<(const node &x) const
    {
        return c < x.c;
    }
} v[N];
int n, k;
ll m;
int f[N];
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<pii, vector<pii>, greater<pii>> q2, q3;
int main()
{
    cjf;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i].p >> v[i].c;
    sort(v + 1, v + 1 + n);
    ll sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += v[i].c;
        if (sum > m)
        {
            cout << i - 1 << '\n';
            return 0;
        }
        q1.push(v[i].p - v[i].c);
    }
    if (k == n)
    {
        cout << n << '\n';
        return 0;
    }
    for (int i = k + 1; i <= n; i++)
        q2.push({v[i].c, i}), q3.push({v[i].p, i});
    int res = k;
    for (int i = k + 1; i <= n; i++)
    {
        while (f[q2.top().second])
            q2.pop();
        while (f[q3.top().second])
            q3.pop();
        int p1 = q2.top().second, p2 = q3.top().second;
        int tmp1 = q2.top().first + q1.top(), tmp2 = q3.top().first;
        if (tmp1 < tmp2)
        {
            sum += tmp1;
            q1.pop(), q2.pop();
            q1.push(v[p1].p - v[p1].c);
            f[p1] = 1;
        }
        else
        {
            sum += tmp2;
            q3.pop();
            f[p2] = 1;
        }
        res++;
        if (sum > m)
        {
            cout << res - 1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}