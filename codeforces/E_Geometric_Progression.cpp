#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS 
    int a,x,m;
    cin>>a>>x>>m;
    int sum=0;
    for (int i = 0; i < x; i++)
    {
        sum=(sum+pow(a,i));
        sum=sum%m;
    }
    
    cout<<m;
    return 0;
}