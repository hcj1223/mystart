#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 310;
int n, m, t;
int a[N];
queue<int> q, Q[M];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &t);
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            if (Q[a[x]].empty())
                q.push(a[x]);
            Q[a[x]].push(x);
        }
        else
        {
            cout << Q[q.front()].front() << endl;
            Q[q.front()].pop();
            if (Q[q.front()].empty())
                q.pop();
        }
    }
    return 0;
}