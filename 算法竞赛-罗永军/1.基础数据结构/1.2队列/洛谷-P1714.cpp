#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int a[N], s[N];
deque<int> q;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int res = -INF;
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && i - m > q.front()) // 为什么不是i-m+1?因为前缀和s[i]-s[j-1]
            q.pop_front();
        if (!q.empty())
            res = max(res, s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] >= s[i])
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n", res);
    return 0;
}