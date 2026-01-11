#include "bits/stdc++.h"
using namespace std;
const int N = 1010;
// int count(int n, int x)
// {
//     int low, high = n, i = 1, res = 0;
//     while (high > 0)
//     {
//         int cur = high % 10;
//         low = n % i;
//         high /= 10;
//         res += (high - (x == 0)) * i;
//         if (cur == x)
//             res += low + 1;
//         else if (cur > x)
//             res += i;
//         i *= 10;
//     }
//     return res;
// }

// int main()
// {
//     while (1)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a == 0 && b == 0)
//             break;
//         for (int i = 0; i <= 9; i++)
//         {
//             if (a > b)
//                 swap(a, b);
//             cout << count(b, i) - count(a - 1, i) << ' ';
//         }

//         cout << endl;
//     }
//     return 0;
// }
int count(int n, int i) // 计算从1到n的整数中数字i出现多少次
{
    int res = 0, d = to_string(n).size();
    for (int j = 1; j <= d; j++) // 从左到右第j位上数字i出现多少次
    {
        // l和r是第j位左边和右边的整数 (视频中的abc和efg); dj是第j位的数字
        int p = pow(10, d - j), l = n / p / 10, r = n % p, dj = n / p % 10;
        /*
            n=1234567, j=3
            p=10000
            l=12, r=4567, dj=3
        */
        // 计算第j位左边的整数小于l (视频中xxx = 000 ~ abc - 1)的情况
        if (i)
            res += l * p;
        else
            res += (l - 1) * p; // 如果i = 0, 左边高位不能全为0(视频中xxx = 001 ~ abc - 1)
                                // 计算第j位左边的整数等于l (视频中xxx = abc)的情况
        if (i == dj)
            res += r + 1;
        if (i < dj)
            res += p;
    }
    return res;
}
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        if (a > b)
            swap(a, b);
        for (int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << " ";
        cout << endl;
    }
    return 0;
}