#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    long long m, n;
    cin >> m >> n;
    if (n > m || (m % 2 != 0 && m!=n))
    {
        cout << "NO" << endl;
    }
    else if (m==n)
    {
        cout<<"YES"<<endl;
    }
    
    else
    {
        long long i = m;
        do
        {
            i /= 2;
        } while ((i % 2 == 0));
        if (n%i==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
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