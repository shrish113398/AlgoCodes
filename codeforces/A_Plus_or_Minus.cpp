#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int a,b,c,add,sub;
    cin>>a>>b>>c;
    add=a+b;
    sub=a-b;
    if (c==add)
    {
        cout<<"+"<<endl;
    }
    else if (c==sub)
    {
        cout<<"-"<<endl;
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