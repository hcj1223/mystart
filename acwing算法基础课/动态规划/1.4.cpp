#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int S[N], v[N][N], w[N][N];
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> S[i];
        for (int j = 1; j <= S[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= S[i]; k++)
                if (j >= v[i][k])
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    cout << f[m] << endl;
    return 0;
}