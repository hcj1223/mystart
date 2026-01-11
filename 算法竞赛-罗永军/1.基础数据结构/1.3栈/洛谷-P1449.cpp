#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<int> num;
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int a, b;
            b = num.top(), num.pop();
            a = num.top(), num.pop();
            int c;
            if (s[i] == '+')
                c = a + b;
            else if (s[i] == '-')
                c = a - b;
            else if (s[i] == '*')
                c = a * b;
            else if (s[i] == '/')
                c = a / b;
            num.push(c);
        }
        else if (s[i] == '.')
        {
            num.push(x);
            x = 0;
        }
        else if (s[i] == '@')
            cout << num.top() << endl;
        else
            x = x * 10 + s[i] - '0';
    }
    return 0;
}