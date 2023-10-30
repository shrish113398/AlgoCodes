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
    int diff[n];
    int arr[2 * n];
    int len=0;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }
    bool equal = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n + i])
        {
            equal = 0;
            break;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        diff[i]=(arr[i]+arr[i+n])/2;
        
    }
    if (equal == 1)
    {
        cout << "0";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            len+=abs(diff[i]-arr[n+i]);
        }
        cout<<len<<endl;
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