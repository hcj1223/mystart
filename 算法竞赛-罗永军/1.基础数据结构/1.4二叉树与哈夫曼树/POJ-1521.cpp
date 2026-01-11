#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "END")
            break;
        map<char, int> mp;
        for (int i = 0; i < str.size(); i++)
            mp[str[i]]++;
        priority_queue<int, vector<int>, greater<int> > q;
        for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
            q.push(it->second);
        int res1 = str.size() * 8, res2 = 0;
        if (q.size() == 1)
            res2 = str.size();
        while (q.size() > 1)
        {
            int a, b;
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            q.push(a + b);
            res2 += a + b;
        }
        double res3 = 1.0 * res1 / res2;
        cout << res1 << " " << res2 << " " << fixed << setprecision(1) << res3 << endl;
    }
    return 0;
}