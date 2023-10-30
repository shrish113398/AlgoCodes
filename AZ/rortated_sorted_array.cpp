#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i)
        {
            if (arr[i] < arr[i - 1])
            {
                ind = i;
            }
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