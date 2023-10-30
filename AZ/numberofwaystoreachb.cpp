#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n,m;
    cin>>n>>m;
    long long fnm=1,fn=1,fm=1;
    for (int i = 1; i <= n; i++)
    {
        fn*=i;
    }
    for (int i = 1; i <= n+m; i++)
    {
        fnm*=i;
    }
    for (int i = 1; i <= m; i++)
    {
        fm*=i;
    }
    long long ways=fnm/(fn*fm);
    cout<<ways%1000000007<<endl;
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