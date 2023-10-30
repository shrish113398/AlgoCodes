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
    if (n%2==0 && n%7==0)
    {
        cout<<"Alice"<<endl;
    }
    else if (n%2!=0 && n%9==0)
    {
        cout<<"Bob"<<endl;
    }
    else
    {
        cout<<"Charlie"<<endl;
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