#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, k;
int a[N];
deque<int> q;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && i - k + 1 > q.front())
            q.pop_front();
        while (!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
        if (i - k + 1 > 0)
            cout << a[q.front()] << " ";
    }
    cout << endl;
    while (!q.empty())
        q.pop_back();
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && i - k + 1 > q.front())
            q.pop_front();
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
        if (i - k + 1 > 0)
            cout << a[q.front()] << " ";
    }
    return 0;
}