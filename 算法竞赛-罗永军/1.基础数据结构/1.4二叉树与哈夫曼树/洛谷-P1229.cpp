#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pre, post;
    cin >> pre >> post;
    int res = 0;
    for (int i = 0; i < pre.size() - 1; i++)
        for (int j = 1; j < post.size(); j++)
            if (pre[i] == post[j] && pre[i + 1] == post[j - 1])
                res++;
    res = 1 << res;
    cout << res << endl;
    return 0;
}