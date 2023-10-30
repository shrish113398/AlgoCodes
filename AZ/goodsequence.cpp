#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void solve()
{
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) != mp.end())
        {
            mp[x] += 1;
        }
        else
        {
            mp[x] = 1;
        }
    }
    int count = 0;
    for (auto i : mp)
    {
        if (i.first <= i.second)
        {
            count+=i.second-i.first;
        }
        else
        {
            count+=i.second;
        }
        
    }
    cout << count << endl;
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