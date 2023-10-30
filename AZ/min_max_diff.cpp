#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int n, k;
int arr[100100];
bool check(int x)
{
    int needed=0;
    for (int i = 1; i < n; i++)
    {
        needed+=(((arr[i]-arr[i-1])+x-1)/x)-1;
    }
    return needed<=k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        r = max(r, arr[i] - arr[i - 1]);
    }
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout<<ans<<endl;
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