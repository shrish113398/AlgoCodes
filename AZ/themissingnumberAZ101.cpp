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
        int a[q];
        int b[q-1];
        int c[q-2];
        int suma=0;
        int sumb=0;
        int sumc=0;
        for (int i = 0; i < q; i++)
        {
            cin>>a[i];
            suma+=a[i];
        }
        for (int i = 0; i < q-1; i++)
        {
            cin>>b[i];
            sumb+=b[i];
        }
        for (int i = 0; i < q-2; i++)
        {
            cin>>c[i];
            sumc+=c[i];
        }
        cout<<suma-sumb<<" "<<sumb-sumc<<endl;
        
    }
    return 0;
}