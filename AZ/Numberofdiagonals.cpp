#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    long long m;
    cin >> m;
    long long res =((m-3)*(m-2)*(m-1)*m)/24;
    cout<<res%mod<<endl;
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