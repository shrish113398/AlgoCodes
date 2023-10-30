#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int sum = 0, ind = -1;

    if (arr[0] > m)
    {
        ind = 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > m)
            {
                ind = i;
                break;
            }
        }
        if (sum <= m)
        {
            ind = n ;
        }
    }

    cout << ind << endl;
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