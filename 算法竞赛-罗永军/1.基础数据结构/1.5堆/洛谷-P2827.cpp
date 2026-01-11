#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q, u, v, t;
int a[N];
int Add = 0;
queue<int> max_heap[3];
int main()
{
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--)
        max_heap[0].push(a[i]);
    for (int aTime = 1; aTime <= m; aTime++)
    {
        int aTop = -0x3f3f3f3f, k = 0;
        for (int i = 0; i <= 2; i++)
            if (!max_heap[i].empty() && max_heap[i].front() > aTop)
                aTop = max_heap[i].front(), k = i;
        max_heap[k].pop();
        aTop += Add;
        if (aTime % t == 0)
            cout << aTop << " ";
        int new1 = (long long)aTop * u / v, new2 = aTop - new1;
        max_heap[1].push(new1 - Add - q), max_heap[2].push(new2 - Add - q);
        Add += q;
    }
    cout << endl;
    for (int i = 1; i <= n + m; i++)
    {
        int aMax = -0x3f3f3f3f, k = 0;
        for (int j = 0; j <= 2; j++)
            if (!max_heap[j].empty() && max_heap[j].front() > aMax)
                aMax = max_heap[j].front(), k = j;
        max_heap[k].pop();
        if (i % t == 0)
            cout << aMax + Add << " ";
    }
    return 0;
}