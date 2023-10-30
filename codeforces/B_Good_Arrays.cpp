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
    int sum=0;
    map<int,int> mp;
    int flag=true;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        sum+=arr[i];
        // if (mp[arr[i]]>n/2 && flag)
        // {
        //     flag=false;
        //     cout<<"NO"<<endl;
            
        // }
    }
    if (n==1 && sum==n)
    {
        cout<<"NO"<<endl;
        return;
    }
    
    bool flag=true;
    int i=0;
    while(i<n-1 && sum>0)
    {
        if (arr[i]==1)
        {
            sum-=2;
        }
        else if (arr[i]>=2)
        {
            sum-=1;
        }   
        if (sum<0)
        {
            flag=false;
            cout<<"NO"<<endl;
            return;

        }
            i++;
    }
    if (arr[n-1]==sum)
    {
        sum-=1;
    }
    
    
    // f
    // if (flag)
    // {
    //     cout<<"YES"<<endl;
    // }    
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