#include <bits/stdc++.h>
using namespace std;
int n, m;
list<int> l;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        l.push_back(i);
    auto it = l.begin();
    while (!l.empty())
    {
        for (int i = 1; i < m; i++)
        {
            it++;
            if (it == l.end())
                it = l.begin();
        }
        cout << *it << " ";
        auto next = ++it;
        if (next == l.end())
            next = l.begin();
        l.erase(--it);
        it = next;
    }
    return 0;
}