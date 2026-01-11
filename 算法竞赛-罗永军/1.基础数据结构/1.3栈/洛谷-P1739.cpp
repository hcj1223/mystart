#include <bits/stdc++.h>
using namespace std;
string check(string s)
{
    stack<char> sk;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(')
            sk.push(s[i]);
        else if (s[i] == ')')
        {
            if (sk.empty())
                return "NO";
            else
                sk.pop();
        }
    if (!sk.empty())
        return "NO";
    return "YES";
}
int main()
{
    string s;
    cin >> s;
    cout << check(s) << endl;
    return 0;
}