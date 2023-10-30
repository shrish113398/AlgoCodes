#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p[i] = arr[i];
        if (i)
        {
            p[i] += p[i - 1];
        }
    }
    int l=0,r=-1,sum=0;
    int cnt=0;
    while (l<n)
    {
        while (r+1<n && ((sum+arr[r+1])<=k))
        {
            cnt++;
            r++;
            sum+=arr[r];
        }
        if (r>=l)
        {
            l++;
            sum-=arr[l-1];
        }
        else
        {
            l++;
            r=l-1;
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