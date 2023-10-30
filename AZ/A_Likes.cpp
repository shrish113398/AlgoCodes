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
        int q;
        cin >> q;
        int p=0;
        int n=0;
        while (q--)
        {
            int x;
            cin>>x;
            if (x>0)
            {
                p++;
            }
            else{
                n++;
            }
            
        }
        int i;
        for ( i = 1; i <= p; i++)
        {
            cout<<i<<" ";
        }
        int l=2;
        for (int j = 0; j < n; j++)
        {
            cout<<i-l<<" ";
            l++;
        }


        cout<<endl;


        for (int j = 0; j < n; j++)
        {
            cout<<"1 0 ";
        }
        for (int j = 1; j <= p-n; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
        
        
    }
    return 0;
}