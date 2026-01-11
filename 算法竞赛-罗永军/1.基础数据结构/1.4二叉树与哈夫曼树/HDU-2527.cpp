#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n;
char str[100010];
int main()
{
    while (~scanf("%d", &n))
    {
        while (n--)
        {
            int m;
            scanf("%d", &m);
            scanf("%s", str);
            int len = strlen(str);
            map<char, int> mp;
            for (int i = 0; i < len; i++)
                mp[str[i]]++;
            priority_queue<int, vector<int>, greater<int>> q;
            for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
                q.push(it->second);
            int res = 0;
            if (q.size() == 1)
                res = len;
            while (q.size() > 1)
            {
                int a, b;
                a = q.top(), q.pop();
                b = q.top(), q.pop();
                q.push(a + b);
                res += a + b;
            }
            if (res > m)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
    return 0;
}