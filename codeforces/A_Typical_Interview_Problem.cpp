#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{   //FBFFBFFB
    int q;
    string s;
    cin>>q;
    cin>>s;
    int flag=0;
    string base="FBFFBFFBFBFFBFFBFBFFBFFB";
    for (int i = 0; i < base.size()-q; i++)
    {
        if (s==base.substr(i,q))
        {
            flag=1;
        }
                
        
    }
    if (flag==0)
    {
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
    
    
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