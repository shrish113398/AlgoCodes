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
    vector <int> arr;
    int even=0,odd=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2==0)
        {
            even=even+arr[i];
        }
        else
        {
            odd=odd+arr[i];
        }
        
    }
    if (even>odd)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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