#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n,flag=0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (__gcd(arr[i],arr[j])==1 || __gcd(arr[i],arr[j])==2)
            {
                flag=1;
                break;
            }
            
        }
        if (flag==1)
        {
            break;
        }
        
        
    }
    if (flag==1)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    
    
    
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