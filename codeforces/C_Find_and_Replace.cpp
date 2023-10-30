#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    char s[n];
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 1; j < n; j += 2)
            {
                if (s[i] == s[j] && i != j)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
        else
        {
            for (int j = 0; j < n; j += 2)
            {
                if (s[i] == s[j] && i != j)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                break;
            }
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