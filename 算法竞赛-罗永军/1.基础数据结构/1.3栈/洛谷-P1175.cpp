#include <bits/stdc++.h>
using namespace std;
string str;
map<char, int> mp; // 优先级
void init()
{
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    mp['^'] = 3;
}
queue<char> myChange(stack<char> a)
{
    queue<char> q;
    string res;
    while (!a.empty())
    {
        res.push_back(a.top());
        a.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--)
        q.push(res[i]);
    return q;
}
void myPrint(stack<int> a)
{
    vector<int> res;
    while (!a.empty())
    {
        res.push_back(a.top());
        a.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
}
void myPrint(queue<char> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
int main()
{
    cin >> str;
    init();
    stack<char> op, res;
    for (int i = 0; i < str.size(); i++)
    {
        // cout << "i: " << i << endl;
        // cout << "op: " << endl;
        // myPrint(op);
        // cout << "res: " << endl;
        // myPrint(res);
        if (str[i] >= '0' && str[i] <= '9')
            res.push(str[i]);
        else if (str[i] == ')')
        {
            while (op.top() != '(')
            {
                char t = op.top();
                op.pop();
                res.push(t);
            }
            op.pop();
        }
        else if (str[i] == '^' || str[i] == '(')
            op.push(str[i]);
        else
        {
            while (!op.empty() && mp[op.top()] >= mp[str[i]])
            {
                char t = op.top();
                op.pop();
                res.push(t);
            }
            op.push(str[i]);
        }
    }
    while (!op.empty())
    {
        res.push(op.top());
        op.pop();
    }
    stack<int> num;
    queue<char> q = myChange(res);
    myPrint(q);
    cout << endl;
    while (!q.empty())
    {
        // myPrint(q);
        // cout << endl;
        char t = q.front();
        q.pop();
        if (t >= '0' && t <= '9')
            num.push(t - '0');
        else
        {
            int a, b;
            b = num.top(), num.pop();
            a = num.top(), num.pop();
            if (t == '+')
                num.push(a + b);
            else if (t == '-')
                num.push(a - b);
            else if (t == '*')
                num.push(a * b);
            else if (t == '/')
                num.push(a / b);
            else if (t == '^')
                num.push(pow(a, b));
            myPrint(num);
            if (!q.empty())
                myPrint(q);
            cout << endl;
        }
    }
    return 0;
}