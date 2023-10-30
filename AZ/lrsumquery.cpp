#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int mod = 1e9 + 7;
inline int add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
int main()
{
    IOS int t;
    int n;
    cin >> n;
    cin >> t;
    int arr[n];
    int sum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[i] = add(sum[i], arr[i]);
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        int ans = sum[r] - sum[l] + arr[l];
        if (ans < 0)
        {
            cout << mod + ans << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}
