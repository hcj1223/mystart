#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int n, m;
struct node
{
    int a, b, c, x, y;
    bool operator<(const node &t) const
    {
        return y > t.y;
    }
} v[N];
int main()
{
    priority_queue<node> q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {    
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].x = 1, v[i].y = v[i].a + v[i].b + v[i].c;
        q.push(v[i]);
    }
    while (m--)
    {
        node t = q.top();
        q.pop();
        cout << t.y << " ";
        t.x++, t.y = t.a * t.x * t.x + t.b * t.x + t.c;
        q.push(t);
    }
    return 0;
}