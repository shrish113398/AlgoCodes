#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        if (l * 2 > r)
        {
            cout << "1 " << r - l + 1 << "\n";
            continue;
        }
        int cnt = 1, p = 1;
        for (int i = l * 2; i <= r; i *= 2)
        {
            ++cnt;
            p *= 2;
        }
        int ans = (r / p) - (l - 1) + max(0ll, (r / (p / 2 * 3)) - (l - 1)) * (cnt - 1);
        cout << cnt << " " << ans%mod << "\n";
    }
    return 0;
}