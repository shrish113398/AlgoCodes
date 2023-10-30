#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    string a,b;
    cin>>a;
    cin>>b;
    int flag=0;
    int ind;
    for (int i = 0; i < a.size()-1; i++)
    {
        for (int j = 0; j < b.size()-1; j++)
        {
            if (a.substr(i,2)==b.substr(j,2))
            {
                flag=1;
                ind=i;
            }
            
        }
        
    }
    if (a==b)
    {
        cout<<"YES"<<endl;
        cout<<a<<endl;
    }
    
    else if (a[0]==b[0])
    {
        cout<<"YES"<<endl;
        cout<<a[0]<<"*"<<endl;
    }
    else if (a[a.size()-1]==b[b.size()-1])
    {
        cout<<"YES"<<endl;
        cout<<"*"<<a[a.size()-1]<<endl;
    }
    else if (flag==1)
    {
        cout<<"YES"<<endl;
        cout<<"*"<<a.substr(ind,2)<<"*"<<endl;
    }
    else
    {
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