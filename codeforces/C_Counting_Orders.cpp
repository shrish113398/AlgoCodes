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
    int arr[n];
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    sort(brr, brr + n);
    long long int a=1;
    for (int i = 0; i < n; i++)
    {
        int upper1 =( upper_bound(arr, arr + n, brr[i]) - arr - 1)%1000000007;
        if (upper1==n)
        {
            a=0;
            break;
        }
        a%=1000000007;
        a=a*(i-upper1);
        a%=1000000007;
        
    }
    cout<<a<<endl;
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