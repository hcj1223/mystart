#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int l[N], r[N];
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
            l[i] = l[k], r[i] = k, r[l[k]] = i, l[k] = i;
        else
            l[i] = k, r[i] = r[k], l[r[k]] = i, r[k] = i;
    }
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        int lx = l[x], rx = r[x];
        r[lx] = rx, l[rx] = lx;
        l[x] = r[x] = 0;
    }
    int j;
    for (int i = 1; i <= n; i++)
        if (!l[i] && r[i])
        {
            j = i;
            break;
        }
    for (int i = j;; i = r[i])
    {
        if (!(l[i] == 0 && r[i] == 0))
            cout << i << " ";
        if (l[i] && !r[i])
            break;
    }
    return 0;
}