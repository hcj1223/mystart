#include <bits/stdc++.h>
using namespace std;

const int N = 15000, M = 1010;
int n, m;
int V[M], W[M], S[M];
int v[N], w[N];
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> V[i] >> W[i] >> S[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        while (k <= S[i])
        {
            cnt++;
            v[cnt] = V[i] * k, w[cnt] = W[i] * k;
            S[i] -= k;
            k *= 2; // 分成1，2，4，8，...
        }
        if (S[i])
        {
            cnt++;
            v[cnt] = V[i] * S[i], w[cnt] = W[i] * S[i];
        }
    }
    n = cnt;
    for (int i = 1; i <= n; i++) // 转化为取不取该堆的01背包问题
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}