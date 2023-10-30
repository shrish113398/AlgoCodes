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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int sub[n-1];
    int req=0;
    for (int i = 0; i < n-1; i++)
    {
        sub[i]=arr[i]-arr[i+1];
        if (sub[i]>0)
        {
            req=max(req,arr[i]);
        }
        
    }
    cout<<req<<endl;
    
    
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