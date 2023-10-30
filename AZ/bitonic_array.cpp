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
    cin>>arr[0];
    int mx=arr[0];
    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > mx)
        {
            mx = arr[i];
            ind = i;
        }
    }
    // cout<<mx<<" "<<ind<<endl;
    while (q--) // O(Q)
    {
        int x;
        cin >> x;
        if (x == mx)
        {
            cout << ind+1 << endl;
        }
        else
        {
            // binary search in 0 to ind and ind to n-1
            int l1 = 0;
            int r1 = ind;
            int l2 = ind;
            int r2 = n - 1;

            while (l1 <= r1) // log(N)
            {
                int mid = l1 + (r1 - l1) / 2;
                if (arr[mid] == x)
                {
                    cout << mid + 1 << " ";
                    break;
                }
                if (arr[mid] > x)
                {
                    r1 = mid - 1;
                }
                else
                {
                    l1 = mid + 1;
                }
            }
            while (l2 <= r2) // log(N)
            {
                int mid = l2 + (r2 - l2) / 2;
                if (arr[mid] == x)
                {
                    cout << mid + 1 << endl;
                    break;
                }
                if (arr[mid] < x)
                {
                    r2 = mid - 1;
                }
                else
                {
                    l2 = mid + 1;
                }
            }
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