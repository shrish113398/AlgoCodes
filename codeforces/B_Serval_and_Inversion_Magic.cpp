#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f1 = -1, f2 = -1, f3 = -1;
    char inv[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        inv[i] = s[n - 1 - i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != inv[i] && f1 == -1)
        {
            f1 = i;
        }
        else if (f1 != -1 && (s[i] == inv[i]) && f2 == -1)
        {
            f2 = i;
        }
        else if (f1 != -1 && f2 != -1 && s[i] != inv[i] && f3 == -1)
        {
            f3 = i;
        }
    }
    for (int i = f1; i < f2; i++)
    {
        if (s[i] == '1')
        {
            s[i] = '0';
        }
        else
            s[i] = '1';
    }
    int f4 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            f4 = 1;
            break;
        }
    } // checking start...........
    // cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<s[i];
    // }
    // cout<<endl;
    // for (int i = 0; i < n/2; i++)
    // {
    //     cout<<inv[i];
    // }
    // cout<<endl;
    // checking ends..........
    if (f3 != -1 || f4 == 1)
    {
        cout << "No" << endl;
    }
    else if (f3 == -1 && f4 == 0)
    {
        cout << "Yes" << endl;
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