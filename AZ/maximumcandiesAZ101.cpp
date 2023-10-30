#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, b;
    cin >> n >> b;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int sum = 0;
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > b)
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        cout << n << endl;
    }
    else
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