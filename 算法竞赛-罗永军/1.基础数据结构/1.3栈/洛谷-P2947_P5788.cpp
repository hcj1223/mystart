#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N], res[N];
stack<int> sk;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 0; i--)
    {
        while (!sk.empty() && a[sk.top()] <= a[i])
            sk.pop();
        if (sk.empty())
            res[i] = 0;
        else
            res[i] = sk.top();
        sk.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << endl;
    return 0;
}