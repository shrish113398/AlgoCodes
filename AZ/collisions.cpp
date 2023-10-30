#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> xaxis[n];
    pair<int, int> yaxis[m];
    for (int i = 0; i < n; i++)
    {
        cin >> xaxis[i].first >> xaxis[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> yaxis[i].first >> yaxis[i].second;
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