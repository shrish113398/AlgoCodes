#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
    
void solve()
{
    int n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int diff[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = arr[i + 1] - arr[i];
    }
    int temp = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {

        if (diff[i] == diff[i - 1])
        {
            ++temp;
        }
        else
        {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    ans = max(ans, temp);
    cout << (ans + 1) << endl;
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