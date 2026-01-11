#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n;
int a[N], s[N];
deque<int> q;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int m = 2 * n;
    for (int i = n + 1; i < m; i++)
        a[i] = a[i - n];
    for (int i = 1; i < m; i++)
        s[i] = s[i - 1] + a[i];
    // 窗口大小为n的单调队列中最小前缀和>=0
    int res = 0;
    for (int i = 1; i < m; i++)
    {
        if (!q.empty() && i - n + 1 > q.front())
            q.pop_front();
        while (!q.empty() && s[q.back()] >= s[i])
            q.pop_back();
        q.push_back(i);
        if (i >= n && s[q.front()] - s[i - n] >= 0)
            res++;
    }
    printf("%d\n", res);
    return 0;
}