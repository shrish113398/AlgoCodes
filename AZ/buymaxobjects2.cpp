#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
}
int main()
{
    IOS int q;
    int n;
    cin >> n;
    cin >> q;
    int arr[n];
    int sum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    while (q--)
    {
        int x;
        cin >> x;
        cout << upper_bound(sum, sum + n, x) - sum << endl;
    }

    return 0;
}