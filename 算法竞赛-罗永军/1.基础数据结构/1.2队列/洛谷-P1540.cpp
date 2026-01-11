#include <bits/stdc++.h>
using namespace std;
int m, n;
deque<int> dq;
const int N = 1010;
int st[N];
int main()
{
    cin >> m >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!st[x])
        {
            res++;
            if (dq.size() < m)
            {
                dq.push_back(x);
                st[x] = 1;
            }
            else
            {
                int t = dq.front();
                dq.pop_front();
                st[t] = 0;
                dq.push_back(x);
                st[x] = 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}