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
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[n];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[n];
    }
    int c[n];
    for (int  i = 0; i < n; i++)
    {
        c[i]=-1*(double)b[i]/(double)a[i];
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<c[i]<<" ";
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