#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
char s[N][15];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    while (m--)
    {
        char t[15];
        int x;
        cin >> t >> x;
        int lent = strlen(t);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int lens = strlen(s[i]);
            int f[15][15];
            memset(f, 0, sizeof f);
            for (int j = 0; j <= lent; j++)
                f[0][j] = j;
            for (int j = 0; j <= lens; j++)
                f[j][0] = j;
            for (int j = 1; j <= lens; j++)
                for (int k = 1; k <= lent; k++)
                {
                    f[j][k] = min(f[j - 1][k] + 1, f[j][k - 1] + 1);
                    if (s[i][j - 1] == t[k - 1])
                        f[j][k] = min(f[j][k], f[j - 1][k - 1]);
                    else
                        f[j][k] = min(f[j][k], f[j - 1][k - 1] + 1);
                }
            if (f[lens][lent] <= x)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}