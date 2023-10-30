#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c == a && d == b)
    {
        cout << "0" << endl;
    }
    else if ((d < b) || ((c - a) > (d - b)))
    {
        cout << "-1" << endl;
    }
    else
    {
        if ((c-a)==0)
        {
            cout<<(d-b)*2<<endl;
        }
        else 
        {
            cout<<(d-b)+((d-b)-(c-a))<<endl;
        }      
        

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