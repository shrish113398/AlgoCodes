#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            brr[i] = arr[i];
        }
        else
            brr[i] = brr[i - 1] + arr[i];
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        if (l != 0)
        {
            if ((brr[l - 1] + (brr[n - 1] - brr[r]) + (r - l + 1) * k) % 2 == 0)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        else
        {
            if (((brr[n - 1] - brr[r]) + (r - l + 1) * k) % 2 == 0)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
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