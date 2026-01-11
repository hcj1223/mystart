#include <bits/stdc++.h>
using namespace std;
int t;
stack<char> sk;
int main()
{
    cin >> t;
    getchar();
    while (t--)
    {
        stack<char> sk;
        while (1)
        {
            char ch = getchar();
            if (ch == ' ' || ch == '\n' || ch == EOF)
            {
                while (!sk.empty())
                {
                    cout << sk.top();
                    sk.pop();
                }
                if (ch == '\n' || ch == EOF)
                    break;
                cout << " ";
            }
            else
                sk.push(ch);
        }
        cout << endl;
    }
    return 0;
}