#include <bits/stdc++.h>
using namespace std;
void solve()
{
}
int main()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n + 1), b;
    map<int, bool> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == false)
        {
            mp[a[i]] = true;
        }
    }
    for (auto it : mp)
    {
        if (it.second == false)
        {
            cnt++;
            b.push_back(it.first);
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
}
