#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m;
int a[N];
deque<int> q;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("0\n");
    for (int i = 1; i < n; i++)
    {
        if (!q.empty() && i - m + 1 > q.front())
            q.pop_front();
        while (!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
        printf("%d\n", a[q.front()]);
    }
    return 0;
}