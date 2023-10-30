#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n, k;
    cin >> n >> k;
    int min;
    int a[n];
    multiset<int> mt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        mt.insert(a[i]);
        if (i - k >= 0)
            mt.erase(mt.find(a[i - k]));
        if (i >= (k - 1))
        {
            cout << *mt.end() << endl;
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