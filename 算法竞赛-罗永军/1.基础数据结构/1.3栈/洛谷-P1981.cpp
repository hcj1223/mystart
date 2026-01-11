#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;
stack<int> nums;
stack<char> ops;
int main()
{
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            x = x * 10 + s[i] - '0';
        else if (s[i] == '+' || s[i] == '*')
        {
            nums.push(x), x = 0;
            if (s[i] == '+')
            {
                while (!ops.empty())
                {
                    char op = ops.top();
                    ops.pop();
                    int a, b, c;
                    b = nums.top(), nums.pop();
                    a = nums.top(), nums.pop();
                    if (op == '*')
                        c = (a * b) % mod;
                    else
                        c = (a + b) % mod;
                    nums.push(c);
                }
            }
            ops.push(s[i]);
        }
    }
    nums.push(x);
    while (!ops.empty())
    {
        char op = ops.top();
        ops.pop();
        int a, b, c;
        b = nums.top(), nums.pop();
        a = nums.top(), nums.pop();
        if (op == '+')
            c = (a + b) % mod;
        else
            c = a * b % mod;
        nums.push(c);
    }
    cout << nums.top() % mod << endl;
    return 0;
}