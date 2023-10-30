#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int mid,final,com;
        cin>>mid>>final>>com;
        if (mid==-1 || final==-1)
        {
            cout<<"F\n";
        }
        else if (mid+final>=80)
        {
            cout<<"A\n";
        }
        else if (mid+final>=65  &&  mid+final<80)
        {
            cout<<"B\n";
        }
        else if (mid+final>=50  &&  mid+final<65)
        {
            cout<<"C\n";
        }
        else if (mid+final>=30  &&  mid+final<50)
        {
            if (com>=50)
            {
                cout<<"C\n";
            }
            else
            {
                cout<<"D\n";
            }
            
        }
        else if (mid+final<30)
        {
            cout<<"F\n";
        }
        
        
        
    }
    return 0;
}