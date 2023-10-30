#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    int flag=0;
    if (n==1)
    {
        cout<<"No"<<endl;
    }
    
    else if (n == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i==0)
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            cout<<"No"<<endl;
        }
        else cout<<"Yes"<<endl;
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