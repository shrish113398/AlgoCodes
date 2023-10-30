#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long int

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = upper_bound(a, a + n, x - a[i]) - a;
            if (a[i] <= x - a[i])
                j--;
            ans += j;
        }
        cout << ans << "\n";
    }
    return 0;
}