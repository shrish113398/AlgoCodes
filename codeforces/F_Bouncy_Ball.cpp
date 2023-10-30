#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, m, j1, j2, i1, i2;
    char d[2];
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    cin >> d[0];
    cin >> d[1];
    int x = i1, y = j1;
    int count = 0;
    int flag = 1;
    while (flag)
    {
        if (d[0] == 'U' && d[1] == 'R')
        {
            x++;
            y--;
            if (x == i2 && y == j2)
            {

                break;
            }
            if (x == n)
            {
                d[1] = 'L';
                count++;
            }
            if (y == 1)
            {
                d[0] = 'D';
                count++;
            }
            if (x == n && y == 1)
            {
                flag = 0;
                count--;
                break;
            }
        }
        else if (d[0] == 'U' && d[1] == 'L')
        {
            x--;
            y--;
            if (x == i2 && y == j2)
            {

                break;
            }
            if (x == n)
            {
                d[1] = 'L';
                count++;
            }
            if (y == 1)
            {
                d[0] = 'D';
                count++;
            }
            if (x == n && y == 1)
            {
                flag = 0;
                count--;
                break;
            }
        }
        else if (d[0] == 'D' && d[1] == 'R')
        {
            x++;
            y++;
            if (x == i2 && y == j2)
            {

                break;
            }
            if (x == n)
            {
                d[1] = 'L';
                count++;
            }
            if (y == 1)
            {
                d[0] = 'D';
                count++;
            }
            if (x == n && y == 1)
            {
                flag = 0;
                count--;
                break;
            }
        }
        else if (d[0] == 'D' && d[1] == 'L')
        {
            x--;
            y++;
            if (x == i2 && y == j2)
            {

                break;
            }
            if (x == n)
            {
                d[1] = 'L';
                count++;
            }
            if (y == 1)
            {
                d[0] = 'D';
                count++;
            }
            if (x == n && y == 1)
            {
                flag = 0;
                count--;
                break;
            }
        }
    }
    if (flag == 1)
    {
        cout << count << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
