#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    int q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        int y, x;
        cin >> y >> x;
        if (y == 1)
        {
            cout<<lower_bound(arr,arr+n,x)-arr<<" ";
        }
        else if (y == 2)
        {
            cout<<upper_bound(arr,arr+n,x)-arr<<" ";
        }
        else if (y == 3)
        {
        }
        else if (y == 4)
        {
        }
        else
        {
            cout << "-1 ";
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
        cout << endl;
    }
    return 0;
}