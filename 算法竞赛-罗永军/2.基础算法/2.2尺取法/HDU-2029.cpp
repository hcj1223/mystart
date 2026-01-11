#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        string str;
        cin >> str;
        bool flag = 1;
        for (int i = 0, j = str.size() - 1; i < j; i++, j--)
            if (str[i] != str[j])
            {
                flag = 0;
                break;
            }
        if (flag)
            printf("yes\n");
        else 
            printf("no\n");
    }
    return 0;
}