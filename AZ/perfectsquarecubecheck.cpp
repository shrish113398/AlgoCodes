#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{

    int n, q;
    cin >> q;
    cin >> n;
    int flag = 0;
    if (q == 1)
    {
        for (int i = 0; i < n / 2 && i < 10000; i++)
        {
            if (i * i == n)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        for (int i = 0; i < n / 2 && i < 10000; i++)
        {
            if (i * i * i == n)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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