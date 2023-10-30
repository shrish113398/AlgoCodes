#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = -1;
    int z = 0;
    int ans = 0;
    while (l < n)
    {
        while (r + 1 < n && ((arr[r + 1] == 1 && z <= k) || (arr[r + 1] == 0 && z < k)))
        {
            r++;
            if (arr[r] == 0)
            {
                z++;
            }
        }
        ans = max(ans, r + 1 - l);
        if (r >= l)
        {
            if (arr[l] == 0)
            {
                z--;
            }
            l++;
        }
        else
        {
            l--;
            r = l - 1;
        }
    }
    cout << ans << endl;
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