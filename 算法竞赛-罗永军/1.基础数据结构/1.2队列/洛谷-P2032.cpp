#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, k;
int a[N];
deque<int> q;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && i - k + 1 > q.front())
            q.pop_front();
        while (!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
        if (i - k + 1 > 0)
            printf("%d\n", a[q.front()]);
    }
    return 0;
}