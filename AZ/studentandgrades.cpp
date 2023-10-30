#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<int, bool> m1;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            m1[x] = 1;
        }
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;
            if (m1.count(x))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
                m1[x] = 1;
            }
        }
    }
    return 0;
}