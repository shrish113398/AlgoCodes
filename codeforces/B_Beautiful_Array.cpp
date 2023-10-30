#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    long long n, k, s, b;
    cin >> n >> k >> b >> s;
    long long mx = n * (k - 1) + k * b;
    long long mn = k * b;
    long long a[n];
    if (s < mn || s > mx)
    {
        int ans=-1;
        cout << ans << endl;
    }
    else
    {
        a[n - 1] = min(s, k - 1 + k * b);
        s -= a[n - 1];
        if (n > 1)
        {

            for (int i = 0; i <= n - 2; i++)
            {
                a[i] = 0;
            }
            int i = n - 2;
            while (1)
            {
                a[i] = k - 1;
                s -= a[i];
                if (s < 0)
                {
                    break;
                }
                i--;
            }
            for (int j = 0; j < n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else cout<<a[n-1]<<endl;;
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