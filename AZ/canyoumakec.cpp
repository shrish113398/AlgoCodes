#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    int g = __gcd(a, b);
    if (n % g == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout<<"No"<<endl;
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