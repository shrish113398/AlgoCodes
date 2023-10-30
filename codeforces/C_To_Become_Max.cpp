#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    int mxel=INT_MIN;
    int ind=-1;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if (mxel<=arr[i])
        {
            mxel=arr[i];
            ind =i;
        }
        
    }
    int diff[n-1];
    int maxdif=INT_MIN;
    for (int i = 0; i < n-1; i++)
    {
        diff[i]=arr[i+1]-arr[i];
        maxdif=max(maxdif,diff[i]);
    }
    
    while (k || ind <0)
    {
        arr[ind-1]+=(diff[ind-1]+1);
        k-=(diff[ind-1]+1);
        ind--;
        // if (ind<0)
        // {
        //     break;
        // }
        
       if(ind)diff[ind-1]=arr[ind]-arr[ind-1];
        if (k<0)
        {
            ind++;
            break;
        }
        
    }
    cout<<arr[ind]<<endl;
    
    
    

    
    
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